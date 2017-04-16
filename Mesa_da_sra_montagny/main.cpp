/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: ENERGIA  Problema: Transmissão de Energia
 *
 * O algoritmo gera um grafo a partir das estações e linhas lidas.
 * É rodada uma busca em profundidade a partir da primeira estação e
 * verifica-se se todos os vértices são encontrados na busca, caso
 * sejam, a resposta é normal, caso contrário, falha.
 * */

#include <iostream>

using namespace std;

typedef struct TGrafo{
    int mat [2010][2010];
    int v, a;
}TGrafo;

typedef struct TPilha{
    int v[10000];
    int topo, fundo;
    int tam;
}TPilha;

void fPilhaVazia(TPilha *p)
{
    p->fundo=0;
    p->topo=0;
}//fPilhaVazia()

void empilha(TPilha *P, int x)
{
    (P->v)[P->topo] = x;
    P->topo++;
}//empilha()

int desempilha(TPilha *p)
{
    int aux = (p->v)[p->topo];
    p->topo--;
    return aux;
}//desempilha()

int pilhaVazia(TPilha *p)
{
    return p->topo==p->fundo ? 1 : 0;
}//pilhaVazia()

void fGrafoVazio(TGrafo *G, int v)
{
    G->v = v;
    G->a = 0;
    for(int i=0; i<=G->v; i++)
    {
        for(int j=0; j<=G->v; j++)
        {
            (G->mat)[i][j] = 0;
        }
    }
}//fGrafoVazio()

void insereAresta(int v, int w, TGrafo *G)
{
    (G->mat)[v][w] = 1;
    (G->a)++;
}//insereAresta()

int proxAdj(TGrafo *G, int cores[], int linha, int coluna)
{
    for(int i=coluna; i<=G->v; i++)
    {
        if((G->mat)[linha][i]!=0)
        {
            if(cores[i]==0)
            {
                return i;
            }//if
        }//if
    }//for
    return 0;
}

void dfs(TGrafo *G, int cores[], int *cont, int vertice)
{
    int prox, auxVertice=vertice, flag=0;
    cores[vertice] = 1;
    (*cont) ++;

    prox = proxAdj(G, cores, vertice, 1);
    while(prox!=0)
    {
        dfs(G, cores, cont, prox);

        prox = proxAdj(G, cores, vertice, prox+1);
    }//while

    cores[vertice] = 2;
}

void zeraVetor(int v[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        v[i] = 0;
    }
}//zeraVetor()

int conectado(TGrafo *G)
{
    int cores[2010] = {0};
    int cont=0;
    //int vertice = 1;

    dfs(G, cores, &cont, 1);

    if(cont!=G->v)
    {
        return 0;
    }//if

    return 1;
}

void printGrafo(TGrafo *G)
{
    int i, j;

    for(i=0; i<=G->v; i++)
    {
        for(j=0; j<=G->v; j++)
        {
            cout << (G->mat)[i][j] << " ";
        }
        cout << endl;
    }
}//printGrafo()

int bfs(TGrafo *G, int cores[], int cBipartido[], int vertice, int *flag, TPilha *p)
{
    int adj;
    int prox;
    cores[vertice] = 1;

    //pinta vertices adjacentes e empilha
    adj = proxAdj(G, cores, vertice, 1);
    while(adj!=0)
    {
        //empilha
        if(cores[adj]==0)
        {
            empilha(p, adj);
        }

        //pinta
        if(cBipartido[vertice]==1)
            if(cBipartido[adj]!=0)
                *flag = 1;
            else
                cBipartido[adj] = 2;
        else
            if(cBipartido[adj]!=0)
                *flag = 1;
            else
                cBipartido[adj] = 1;
        adj = proxAdj(G, cores, vertice, adj+1);
    }//while

    prox = desempilha(p);

    bfs(G, cores, cBipartido, prox, flag, p);

    cores[vertice] = 2;
}//bfs()

int bipartido(TGrafo *G)
{

}//bipartido()

int main()
{
    TGrafo *G = (TGrafo*) malloc(sizeof(TGrafo));

    int n, m;
    int a, b;
    int resultado, cont=0;

    /*cin >> n;
    cin >> m;*/


    while(cin >> n >> m)
    {
        cont ++;
        fGrafoVazio(G, n);

        for(int i=0; i < m; i++)
        {
            cin >> a;
            cin >> b;

            insereAresta(a, b, G);
            insereAresta(b, a, G);
        }//for

        resultado = bipartido(G);
        if(resultado==1)
        {
            cout << "Instancia " << cont << endl;
            cout << "sim" << endl << endl;
        }else
        {
            cout << "Instancia " << cont << endl;
            cout << "nao" << endl << endl;
        }

        cin >> n;
        cin >> m;
    }

    free(G);

    return 0;
}//main()