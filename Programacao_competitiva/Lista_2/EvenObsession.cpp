#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <stdio.h>

#define INFINITO 100000000
#define MAX_VERTICES 10010

class Grafo{
private :
    int v;  //Número de vértices
    std::list<std::pair<int,int> > * adj;

public:
    Grafo(int v)
    {
        this->v = v;

        adj = new std::list<std::pair<int, int> >[v+10];
    }//Grafo()

    void addAresta(int v1, int v2, int custo)
    {
        (this->adj)[v1].push_back(std::make_pair(v2,custo));
        (this->adj)[v2].push_back(std::make_pair(v1,custo));
    }//addAresta()

    void add1(int v1, int v2, int custo)
    {
        (this->adj)[v1].push_back(std::make_pair(v2,custo));
    }//addAresta()

    int dijkstra(int origem, int destino)
    {
        //Vetor de distâncias de cada vertice à origem
        int dist[MAX_VERTICES];
        //Vetor com os vértices visitados
        int visitados[MAX_VERTICES];
        std::priority_queue<std::pair<int,int>,
                std::vector<std::pair<int, int> >,
                std::greater<std::pair<int, int> > > heap;

        for(int i=0; i<=this->v; i++)
        {
            dist[i] = INFINITO;
            visitados[i] = false;
        }//for

        dist[origem] = 0;

        //Insere origem no heap
        heap.push(std::make_pair(dist[origem], origem));

        while(!heap.empty())
        {
            std::pair<int, int> p = heap.top();
            int u = p.second;
            heap.pop();

            if(visitados[u]==false)
            {
                visitados[u] = true;

                std::list<std::pair<int, int> >::iterator it;

                for(it=adj[u].begin(); it!=adj[u].end(); it++)
                {
                    //obtém o vértice adjacente
                    int v = it->first;
                    int custo_aresta = it->second;

                    //relaxamento
                    if(dist[v]>dist[u]+custo_aresta)
                    {
                        dist[v] = dist[u]+custo_aresta;
                        heap.push(std::make_pair(dist[v], v));
                    }//if

                }//for
            }//if
        }//while

        return dist[destino];
    }//dikstra()

    void leGrafo(int arestas)
    {
        int v1, v2, custo;
        for(int i=0; i<arestas; i++)
        {
            std::cin >> v1 >> v2 >> custo;
            addAresta(v1, v2, custo);
        }//for
    }//leGrafo()

    void turnEven(Grafo *G)
    {
        std::list<std::pair<int,int> >::iterator it, it2;
        for(int i=1; i<=this->v; i++)
        {
            for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
            {
                for(it2=this->adj[it->first].begin(); it2!=this->adj[it->first].end(); it2++)
                {
                    if(i != it2->first)
                        G->add1(i, it2->first, it2->second+it->second);
                }
            }
        }
    }

    void print()
    {
        std::list<std::pair<int,int> >::iterator it;
        for(int i=1; i<=this->v; i++)
        {
            printf("%d : ", i);
            for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
            {
                printf("<%d, %d>, ", it->first, it->second);
            }
            printf("\n");
        }
    }
};

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    Grafo G(n);
    Grafo N(n);
    G.leGrafo(m);
    G.turnEven(&N);

    //G.print();
    //printf("\n");
    //N.print();

    int distancia = N.dijkstra(1, n);
    printf(distancia==INFINITO ? "-1\n" : "%d\n", distancia);


    /*
    for(int i=0;i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            distancia = G.dijkstra(i, j);
            if(distancia==INFINITO)
                cout << "distancia " << i << " para " << j << ": " <<
                "INFINITO" << endl;
            else
                cout << "distancia " << i << " para " << j << ": " <<
                distancia << endl;
        }//for
    }//for 
    */

    return 0;
}