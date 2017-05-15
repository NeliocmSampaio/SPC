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

    int vertice(int i, int j)
    {
        return (i*8) + j;
    }

    void geraGrafo()
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                std::cout << vertice(i, j) << std::endl;
                if(i-2 >=0 && j-1>=0)
                    addAresta(vertice(i, j), vertice(i-2, j-1), 1);
                if(i-1>=0 && j-2>=0)
                    addAresta(vertice(i, j), vertice(i-1, j-2), 1);

                if(i-2 >=0 && j+1>=0)
                    addAresta(vertice(i, j), vertice(i-2, j+1), 1);
                if(i-1>=0 && j+2>=0)
                    addAresta(vertice(i, j), vertice(i-1, j+2), 1);

                if(i+2 >=0 && j-1>=0)
                    addAresta(vertice(i, j), vertice(i+2, j-1), 1);
                if(i+1>=0 && j-2>=0)
                    addAresta(vertice(i, j), vertice(i+1, j-2), 1);

                if(i+2 >=0 && j+1>=0)
                    addAresta(vertice(i, j), vertice(i+2, j+1), 1);
                if(i+1>=0 && j+2>=0)
                    addAresta(vertice(i, j), vertice(i+1, j+2), 1);
            }//for
        }//for
    }//geraGrafo()

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

void getVertice(string x, string y, int *a, int *b)
{
    char p1, p2;
    int iP1, iP2;

    p1 = x[0];
    p2 = x[1];
    iP1 = p1 % 'a';
    iP2 = p2 - '0';

    //cout << iP1 << " " << iP2 << endl;

    *a = ((8-iP2)*8) + iP1;

    p1 = y[0];
    p2 = y[1];
    iP1 = p1 % 'a';
    iP2 = p2 - '0';

    //cout << iP1 << " " << iP2 << endl;

    *b = ((8-iP2)*8) + iP1;

}

int main() {
    string x, y;
    int a, b;

    Grafo g(65);
    g.geraGrafo();

    while(cin >> x >> y)
    {
        getVertice(x, y, &a, &b);

        cout << g.dijkstra(a, b) << endl;

    }

    return 0;
}