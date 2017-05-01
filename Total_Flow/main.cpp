/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: MTOTALF  Problema: Total Flow
 *
 * O algoritimo transforma a entrada em um grafo sendo os encaixes dos canos os vértices
 * e os canos as arestas com os pesos equivalentes à capacidade dos canos. No grafo gerado,
 * executa-se o algoritmo de fluxo máximo de Edmond's Karp para obter o fluxo máximo nos canos.
 *
 * Obs.: A implementação do algoritmo utilizada foi a passada pelo monitor da disciplina
 * Lucas Jose Carneiro Maciel.
 *
 * */

#include <bits/stdc++.h>

#define MAXV 1010 // the maximum number of vertices

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

graph g;


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

void addaresta(int a, int b, int f)
{
    if(g.flow[a][b]!= 0)
    {
        g.flow[a][b] = g.flow[a][b] + f;
    } else
    {
        g.edges[a].push_back(b);    // Adiciona a aresta de 0 para 1
        g.edges[a].push_back(b);    // NAO SE ESQUECA DE ADICIONAR A ARESTA DE VOLTA: caso esqueca o algoritmo
                                    // nao sera capaz de corrigir o fluxo e a resposta ficará incorreta.
        g.flow[a][b] = f;           // Altere a capacidade da aresta via a matriz de adjacencia 'flow'
    }
}


int main(){
    int n;
    int v1, v2, f;
    char a, b;

    cin >> n;
    init(g, MAXV);

    for(int i=0; i<n; i++)
    {
        cin >> a >> b >> f;
        if(isupper(a))
            v1 = a%65;
        else
            v1 = a%65-6;//97
        if(isupper(b))
            v2 = b%65;
        else
            v2 = b%65-6;

        if (v2==25)
            v2 = n+1;

        addaresta(v1, v2, f);
    }

    cout << maxFlow(g, 0, n+1) << endl;

    return 0;
}