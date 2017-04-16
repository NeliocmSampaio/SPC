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

    //cout << "debug 2" << endl;
    /*for(int i=1; i<=(G->v); i++)
    {
        cont = 0;
        zeraVetor(cores, G->v+1);
        dfs(G, cores, &cont, i);

        if(cont!=G->v)
        {
            return 0;
        }
    }*/
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

    int e, l;
    int a, b;
    int resultado, cont=0;

    cin >> e;
    cin >> l;


    while(e!=0)
    {
        cont ++;
        fGrafoVazio(G, e);
        //printGrafo(G);

        for(int i=0; i<l; i++)
        {
            cin >> a;
            cin >> b;

            insereAresta(a, b, G);
            insereAresta(b, a, G);
        }//for

        resultado = conectado(G);
        if(resultado==1)
        {
            cout << "Teste " << cont << endl;
            cout << "normal" << endl << endl;
        }else
        {
            cout << "Teste " << cont << endl;
            cout << "falha" << endl << endl;
        }

        cin >> e;
        cin >> l;
    }

    free(G);

    return 0;
}//main()