/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: CAVALOS      Problema: A lei vai a Cavalo!
 *
 * O algoritmo gera um grafo bipartido com as relações entre soldados e cavalos, cria arestas
 * da origem para cada soldado com peso 1 e arestas com peso igual a quantidade de soldados
 * que cada cavalo pode ser montado até um vértice destino. Nesse grafo, com o algoritmo de
 * fluxo máximo de Edmonds Karp, obtém-se o número máximo de soldados que podem ter um cavalo
 * para montar.
 *
 * Obs.: A implementação do algoritmo utilizada foi a passada pelo monitor da disciplina
 * Lucas Jose Carneiro Maciel.
 *
 * */

#include <bits/stdc++.h>

#define MAXV 210 // the maximum number of vertices

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

void addaresta(int a, int b, int f)
{
    g.edges[a].push_back(b); // Adiciona a aresta de 0 para 1
    g.edges[b].push_back(a); // NAO SE ESQUECA DE ADICIONAR A ARESTA DE VOLTA: caso esqueca o algoritmo
    // nao sera capaz de corrigir o fluxo e a resposta ficará incorreta.
    g.flow[a][b] = f;        // Altere a capacidade da aresta via a matriz de adjacencia 'flow'
}

void origemSold(int s, int c)
{
    for(int i=c+1; i<=s+c; i++)
    {
        addaresta(0, i, 1);
    }
}//origemCav()

void fimCav(int c, int f, int cav[])
{
    for(int i=1; i<=c; i++)
    {
        addaresta(i, f, cav[i]);
    }
}

int main(){
    int n, m, k;
    int a, b, f;
    int cavalos[110];
    int cont=1;

    while(scanf("%d %d %d", &n, &m, &k)!=EOF)
    {
        init(g, n+m+2);

        for (int i=1; i<=n; i++)
        {
            //cin >> cavalos[i];
            scanf("%d", &cavalos[i]);
        }//for

        for(int i=0; i<k; i++)
        {
            //cin >> a >> b;
            scanf("%d %d", &a, &b);
            b = (b+n);
            addaresta(b, a, 1);
        }
        origemSold(m, n);
        fimCav(n, n+m+1, cavalos);

        //cout << "Instancia " << cont << endl;
        //cout << maxFlow(g, 0, n+m+1) << endl; //rode o fluxo entre o source e o sink
        printf("Instancia %d\n", cont);
        printf("%d\n", maxFlow(g, 0, n+m+1));

        cont++;
    }

    return 0;
}