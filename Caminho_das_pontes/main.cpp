/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: PONTES09     Problema: Caminho das pontes
 *
 * O algoritmo gera um grafo com os pilares como vértices, as pontes como arestas e
 * o número de buracos como os pesos das arestas. Assim, com o algoritmo de Djikstra,
 * obtém-se o número mínimo de buracos a serem pulados.
 * */

#include <iostream>
#include <list>
#include <queue>
#include <utility>

#define INFINITO 10000000000
#define MAX_VERTICES 10000

class Grafo{
private :
    int v;  //Número de vértices
    std::list<std::pair<int,int>> * adj;

public:
    Grafo(int v)
    {
        this->v = v+1;

        adj = new std::list<std::pair<int, int>>[v+1];
    }//Grafo()

    void addAresta(int v1, int v2, int custo)
    {
        (this->adj)[v1].push_back(std::make_pair(v2,custo));
    }//addAresta()

    long int dijkstra(int origem, int destino)
    {
        //Vetor de distâncias de cada vertice à origem
        long int dist[MAX_VERTICES];
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
            addAresta(v2, v1, custo);
        }//for
    }//leGrafo()
};

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    Grafo G(n+1);
    G.leGrafo(m);

    long int distancia;

    distancia = G.dijkstra(0, n+1);
    cout << distancia << endl;

    return 0;
}