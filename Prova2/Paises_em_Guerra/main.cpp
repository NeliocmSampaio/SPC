#include <iostream>
#include <list>
#include <queue>
#include <utility>

#define INFINITO 100000000
#define MAX_VERTICES 100

using namespace std;

class Grafo{
private :
    int v;  //Número de vértices
    std::list<std::pair<int,int>> * adj;

public:
    Grafo(int v)
    {
        this->v = v;

        adj = new std::list<std::pair<int, int>>[v+1];
    }//Grafo()

    void addAresta(int v1, int v2, int custo)
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

        for(int i=0; i<this->v; i++)
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

                std::list<std::pair<int, int>>::iterator it;

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

    void print()
    {
        for (int i=1; i<=v; i++)
        {
            std::list<std::pair<int, int>>::iterator it;
            printf("v[%d]", i);
            for(it=adj[i].begin(); it!=adj[i].end(); it++)
            {
                printf(" -> (%d, %d)", it->first, it->second);
            }//for
            printf(";\n");
        }//for
    }//print

    int DFS(int v, char visitados[], bool *flag)
    {
        visitados[v] = 1;

        int u, peso;

        std::list<std::pair<int, int>>::iterator it;
        for(it=adj[v].begin(); it!=adj[v].end(); it++)
        {
            u = it->first;
            peso = it->second;

            if(visitados[u]!=2)
            {
                if(visitados[u]==0)
                {
                    DFS(u, visitados, flag);
                }else
                {
                    it->second = 0;
                    visitados[u] = 4;   //marcar como ciclo até esse vértice;
                    *flag = true;
                }//else
            }//if

            if(*flag)
            {
                if(visitados[v] == 4)
                {
                    *flag = false;
                }
                it->second = 0;
            }//if

        }//for



        visitados[v] = 2;

        return 0;
    }

    void zeraCustoCiclos()
    {
        char visitados[v];

        std::list<std::pair<int, int>>::iterator it;
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {

        }
    }//zeraCustoCiclos()
};

using namespace std;

int main() {
    int n, e;
    int v1, v2, custo;
    int k;
    int partida, destino;

    scanf("%d %d", &n, &e);

    while(n!=0)
    {
        Grafo g(n);

        g.leGrafo(e);

        g.print();

        scanf("%d %d", &n, &e);
    }

    return 0;
}