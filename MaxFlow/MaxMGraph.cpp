#include <iostream>
#include <list>
#include <queue>
#include <utility>

#define INFINITO 100000000
#define MAX_VERTICES 100

class Grafo{
private :
    int v;  //Número de vértices
    std::list<std::pair<int,int>> * adj;
    int flow[MAX_VERTICES][MAX_VERTICES];

public:
    Grafo(int v)
    {
        this->v = v;

        adj = new std::list<std::pair<int, int>>[v];
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

    Grafo Atualiza_Grafo_Residual()
    {
        Grafo g(v);

        for(int i=0; i<v; i++)
        {
            std::list<std::pair<int, int>>::iterator it;

            for(it=adj[i].begin(); it!=adj[i].end(); it++) {
                //obtém o vértice adjacente
                int v = it->first;
                int custo_aresta = it->second;

                g.addAresta(i, v, 0);
            }//for
        }//for

        return g;
    }

    void Ford_Fulkerson()
    {

    }

    void leGrafo(int arestas)
    {
        int v1, v2, custo;
        for(int i=0; i<arestas; i++)
        {
            std::cin >> v1 >> v2 >> custo;
            addAresta(v1, v2, custo);
        }//for
    }//leGrafo()
};

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    Grafo G(n);
    G.leGrafo(m);

    int distancia;

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

    return 0;
}