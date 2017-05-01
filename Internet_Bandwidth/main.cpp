/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 820  Problema: Internet Bandwidth
 *
 * O algoritmo gera um grafo a partir da entrada e utiliza o algoritmo de fluxo máximo de
 * Edmonds Karp para obter o fluxo máximo entre o vértice source e destination.
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
        g.flow[b][a] = g.flow[b][a] + f;
    } else
    {
        g.edges[a].push_back(b);    // Adiciona a aresta de 0 para 1
        g.edges[b].push_back(a);    // NAO SE ESQUECA DE ADICIONAR A ARESTA DE VOLTA: caso esqueca o algoritmo
        // nao sera capaz de corrigir o fluxo e a resposta ficará incorreta.
        g.flow[a][b] = f;           // Altere a capacidade da aresta via a matriz de adjacencia 'flow'
        g.flow[b][a] = f;
    }
}


int main(){
    int n;
    int a, b, f;
    int begin, end, c;
    int cont=1;


    scanf("%d", &n);

    while(n!=0) {
        init(g, n+5);

        scanf("%d %d %d", &begin, &end, &c);

        for (int i = 0; i < c; i++) {
            scanf("%d %d %d", &a, &b, &f);
            addaresta(a, b, f);
        }//for

        printf("Network %d\n", cont);
        printf("The bandwidth is %d.\n\n", maxFlow(g, begin, end));

        scanf("%d", &n);
        cont ++;
    }//while

    return 0;
}