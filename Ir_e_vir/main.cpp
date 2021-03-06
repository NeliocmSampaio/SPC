/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: IREVIR   Problema: Ir e vir
 *
 * O algoritmo gera um grafo a partir das intercecções e vias lidas e executa
 * uma busca em profundidade para cada vértice, verificando se, a partir do
 * vértice, pode-se alcançar todos os outros.
 * */

#include <iostream>

using namespace std;

typedef struct TGrafo{
    int mat [2010][2010];
    int v, a;
}TGrafo;

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

    //cout << "debug 2" << endl;
    for(int i=1; i<=(G->v); i++)
    {
        cont = 0;
        zeraVetor(cores, G->v+1);
        dfs(G, cores, &cont, i);

        if(cont!=G->v)
        {
            return 0;
        }
    }

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

int main()
{
    TGrafo *G = (TGrafo*) malloc(sizeof(TGrafo));

    int n, m;
    int a, b, p;

    cin >> n;

    while(n!=0)
    {
        fGrafoVazio(G, n);
        //printGrafo(G);
        cin >> m;


        for(int i=0; i<m; i++)
        {
            cin >> a;
            cin >> b;
            cin >> p;

            insereAresta(a, b, G);
            if(p==2) insereAresta(b, a, G);
        }
        //cout << "debug 1" << endl;
        /*printGrafo(G);
        getchar();
        getchar();*/

        cout << conectado(G) << endl;

        cin >> n;
    }

    free(G);

    return 0;
}//main()