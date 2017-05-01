#include <bits/stdc++.h>

#define MAXV 100 // the maximum number of vertices

using namespace std;

/* definicao das estruturas */

struct node{
    int index, parent, cost;
};

/*
   O grafo aqui usa lista de adjacencia para as arestas,
   porem usa matriz de adjacencia para manter os fluxos.

   Poderia usar matriz de adjacencia para as arestas também,
   mas deixa a bfs lenta.
*/

struct graph{
    vector<int> edges[MAXV];
    node nodes[MAXV];
    int flow[MAXV][MAXV];
    int size;
};

bool bfs(graph &g, int a, int b = -1){
    queue< node > q;
    vector<bool> mark(g.size, false);
    q.push(g.nodes[a]);
    while (!q.empty()){
        node v = q.front();
        q.pop();
        if (mark[v.index]) continue;
        mark[v.index] = true;
        g.nodes[v.index] = v;
        if (v.index == b) return true;
        for (int i = 0; i < g.edges[v.index].size(); ++i){
            int j = g.edges[v.index][i];
            if (!mark[j] && g.flow[v.index][j] > 0){
                node tmp = g.nodes[j];
                tmp.cost = v.cost+1;
                tmp.parent = v.index;
                q.push(tmp);
            }
        }
    }
    return false;
}


/* inicializacao do grafo quanto ao numero de vertices */

void init(graph &g, int v){
    g.size = v;
    for (int i = 0; i < v; ++i){
        g.edges[i].clear();
        g.nodes[i].index = i;
        g.nodes[i].parent = -1;
        g.nodes[i].cost = 0;
        for (int j = 0; j < v; ++j)
            g.flow[i][j] = 0;
    }
}

int path_min_capacity(graph &g, int source, int sink){
    node actual = g.nodes[sink];
    int min_capacity = INT_MAX;

    while (actual.parent != -1){
        min_capacity = min(min_capacity, g.flow[actual.parent][actual.index]);
        actual = g.nodes[actual.parent];
    }

    return min_capacity;
}

void path_augment(graph &g, int source, int sink, int min_capacity){
    node actual = g.nodes[sink];

    while (actual.parent != -1){
        g.flow[actual.parent][actual.index] -= min_capacity;
        g.flow[actual.index][actual.parent] += min_capacity;
        actual = g.nodes[actual.parent];
    }
}

/* EDMONDS KARP (fluxo máximo) */

int maxFlow(graph &g, int source, int sink){
    int result = 0, tmp = 0;
    while (true){
        if (!bfs(g, source, sink)) break;
        tmp = path_min_capacity(g, source, sink);
        result += tmp;
        path_augment(g, source, sink, tmp);
    }
    return result;
}

/*
   Suponha o seguinte grafo bi-partido em que queremos
   calcular o matching:
   a -> c
   a -> d
   b -> c

   Logo vamos adicionar dois nós, um source e um sink,
   e iremos colocar a capacidade das arestas como 1
   para haver matching apenas de 1 para 1 no grafo.

Considerando:
    source = 0
    a = 1
    b = 2
    c = 3
    d = 4
    sink = 5

Fazemos:
*/

graph g;

int main(){
    int n = 4;
    init(g, n+2);

    g.edges[0].push_back(1); // Adiciona a aresta de 0 para 1
    g.edges[1].push_back(0); // NAO SE ESQUECA DE ADICIONAR A ARESTA DE VOLTA: caso esqueca o algoritmo
    // nao sera capaz de corrigir o fluxo e a resposta ficará incorreta.
    g.flow[0][1] = 1;        // Altere a capacidade da aresta via a matriz de adjacencia 'flow'

    g.edges[0].push_back(2);
    g.edges[2].push_back(0);
    g.flow[0][2] = 1;

    g.edges[1].push_back(3);
    g.edges[3].push_back(1);
    g.flow[1][3] = 1;

    g.edges[1].push_back(4);
    g.edges[4].push_back(1);
    g.flow[1][4] = 1;

    g.edges[2].push_back(3);
    g.edges[3].push_back(2);
    g.flow[2][3] = 1;

    g.edges[3].push_back(5);
    g.edges[5].push_back(3);
    g.flow[3][5] = 1;

    g.edges[4].push_back(5);
    g.edges[5].push_back(4);
    g.flow[4][5] = 1;

    cout << maxFlow(g, 0, n+1) << endl; //rode o fluxo entre o source e o sink

    return 0;
}