/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: DESVIO       Problema: Desvio de rota
 *
 * O algoritmo transforma a entrada em um grafo (G(v,a))e gera outro grafo (G'(v, a')) a partir deste
 * sendo que uma aresta que pertence à a só pertence à a' se ela não está na rota definida pela empresa
 * ou se ela liga duas cidades subsequentes na rota. A partir desse grafo, com o algoritmo de Djikstra,
 * verifica-se qual a menor rota.
 * */

#include <iostream>
#include <list>
#include <queue>
#include <utility>

#define INFINITO 100000000
#define MAX_VERTICES 10000

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
            addAresta(v2, v1, custo);
        }//for
    }//leGrafo()

    void transformaGrafo(int c, Grafo G)
    {
        std::list<std::pair<int, int>>::iterator it;
        for(int i=0; i<G.v; i++)
        {
            for(it=G.adj[i].begin(); it!=G.adj[i].end(); it++)
            {
                if( i<c )
                {
                    if( (it->first == i+1) || (i == (it->first)+1) )
                    {
                        addAresta(i, it->first, it->second);
                    }//if
                }else
                {
                    addAresta(i, it->first, it->second);
                }
            }
        }//for
    }//transformaGrafo()
};

using namespace std;

int main() {
    int n, m, c, k;

    int distancia;

    cin >> n >> m >> c >> k;
    while (n!=0)
    {
        Grafo G(n);
        G.leGrafo(m);
        Grafo Gl(n);
        Gl.transformaGrafo(c, G);

        distancia = Gl.dijkstra(k, c-1);

        cout << distancia << endl;

        cin >> n >> m >> c >> k;
    }

    return 0;
}