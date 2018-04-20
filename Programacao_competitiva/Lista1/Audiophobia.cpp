#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <stdio.h>

#define INFINITO 100000000
#define MAX_VERTICES 100

class Grafo{
private :
    int v;  //Número de vértices
    std::list<std::pair<int,int> > * adj;

public:
    Grafo(int v)
    {
        this->v = v;

        adj = new std::list<std::pair<int, int> >[v+5];
    }//Grafo()

    void addAresta(int v1, int v2, int custo)
    {
        (this->adj)[v1].push_back(std::make_pair(v2,custo));
        (this->adj)[v2].push_back(std::make_pair(v1,custo));
    }//addAresta()

    int edge(int u, int v)
    {
        std::list<std::pair<int, int> >::iterator it;
        for(it = this->adj[u].begin(); it!= this->adj[u].end(); it++)
        {
            if(it->first == v)
                return it->second;
        }
        return 0;
    }

    int dijkstra(int origem, int destino)
    {
        int max = -1;
        //Vetor de distâncias de cada vertice à origem
        int dist[MAX_VERTICES];
        int ant[MAX_VERTICES];
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

                std::list<std::pair<int, int> >::iterator it;

                for(it=adj[u].begin(); it!=adj[u].end(); it++)
                {
                    //obtém o vértice adjacente
                    int v = it->first;
                    int custo_aresta = it->second;

                    //relaxamento
                    if(dist[v]>dist[u]+custo_aresta)
                    {
                        ant[v] = u;
                        dist[v] = dist[u]+custo_aresta;
                        heap.push(std::make_pair(dist[v], v));
                    }//if

                }//for
            }//if
        }//while

        int a = destino;
        int n = 0;
        int path[MAX_VERTICES];
        while( a != origem )
        {
            path[n] = a;
            n++;
            a = ant[a];
        }

        /*for(int i=0; i<n; i++)
        {
            printf(" %d\n", path[i]);
        }*/

        n--;
        n++;
        
        while(n--)
        {
            printf("%d\n", n);
            if( n-1 > 0)
            {
                int aux = this->edge(ant[n-1], ant[n]);
                //printf("aux: %d\n", aux);
                if( aux > max)
                    max = aux;
            }
        }

        return max;
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
        for(int i=1; i<this->v; i++)
        {
            printf("%d: ", i);
            std::list<std::pair<int, int> >::iterator it;
            for(it=adj[i].begin(); it!=adj[i].end(); it++)
            {
                printf("<%d, %d>  ", it->first, it->second);
            }//for
            printf("\n");
        }//for
    }//print()
};

using namespace std;

int main() {
    int c, s, q;
    int a, b;
    int distancia;
    int cn = 1;

    cin >> c >> s >> q;
    while ( c != 0 )
    {
        //printf("q: %d\n", q);

        Grafo G(c+1);
        G.leGrafo(s);
        //G.print();
        printf("Case #%d\n", cn);
        cn++;
        for( int i=0; i<q; i++)
        {
            cin >> a >> b;

            distancia = G.dijkstra(a, b);

            if(distancia==INFINITO)
            {
                printf("no path\n");
            }else printf("d %d %d: %d\n",a, b, distancia);
        }//for

        cin >> c >> s >> q;
    }//while

    return 0;
}