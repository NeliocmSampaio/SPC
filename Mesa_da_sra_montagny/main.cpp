/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: MESA     Problema: Mesa da Sra Montagny!
 *
 * O algoritmo gera um grafo com as pessoas lidas como vértices e
 * as relações de amizade como arestas. Assim, utiliza-se uma busca em
 * largura para verificar se o grafo é bipartido. Caso seja, a resposta
 * é sim, e não, caso contrário.
 * */

#include <iostream>

using namespace std;

typedef struct TGrafo{
    int mat [110][110];
    int v, a;
}TGrafo;

typedef struct TPilha{
    int v[110];
    int topo, fundo;
    int tam;
}TPilha;

typedef struct TFila{
    int v[110];
    int frente, tras;
    int tam;
}TFila;

//fila
void fFilaVazia(TFila *f)
{
    f->tras=0;
    f->frente=0;
}//fPilhaVazia()

void enfileira(TFila *f, int x)
{
    (f->v)[f->tras] = x;
    f->tras++;
}//empilha()

int filaVazia(TFila *f)
{
    return f->frente==f->tras ? 1 : 0;
}//pilhaVazia()

int desenfileira(TFila *f)
{
    if (filaVazia(f)==1)
        return 0;
    int aux = (f->v)[f->frente];
    f->frente++;
    return aux;
}//desempilha()

//Pilha
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
    int aux = (p->v)[p->topo-1];
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

int proxBipartido(TGrafo *G, int linha, int coluna)
{
    for(int i=coluna; i<=G->v; i++)
    {
        if((G->mat)[linha][i] != 0)
            return i;
    }//for
    return 0;
}//prox()

int bfs(TGrafo *G, int cores[], int cBipartido[], int vertice, int *flag, TFila *f)
{
    //cout << vertice << endl;
    int adj;
    int prox;
    cores[vertice] = 1;

    //pinta vertices adjacentes e enfileira
    adj = proxAdj(G, cores, vertice, 1);
    while(adj!=0) {
        //efileira
        if (cores[adj] == 0) {
            cores[adj] = 2;
            enfileira(f, adj);
        }
        adj = proxAdj(G, cores, vertice, adj+1);
    }

    adj = proxBipartido(G, vertice, 1);
    while(adj!=0)
    {
        //pinta
        if(cBipartido[vertice]==1)
            if(cBipartido[adj]==1)
                return 0;
            else
                cBipartido[adj] = 2;
        else
            if(cBipartido[adj]==2)
                return 0;
            else
                cBipartido[adj] = 1;
        adj = proxBipartido(G, vertice, adj+1);
    }//while

    cores[vertice] = 3;
    prox = desenfileira(f);
    if(prox!=0)
        return bfs(G, cores, cBipartido, prox, flag, f);
    return 1;
}//bfs()

int bipartido(TGrafo *G)
{
    int cores[2010] = {0};
    int cBipartido[2010] = {0};
    TFila *f = (TFila*) malloc(sizeof(TFila));
    int flag = 0;
    int resultado=1;
    //int vertice = 1;

    fFilaVazia(f);
    cBipartido[1] = 1;

    resultado = bfs(G, cores, cBipartido, 1, &flag, f);
    //dfs(G, cores, &cont, 1);

    free(f);

    return resultado;
}//bipartido()

int main()
{
    TGrafo *G = (TGrafo*) malloc(sizeof(TGrafo));

    int n, m;
    int a, b;
    int resultado, cont=0;

    /*cin >> n;
    cin >> m;*/


    while(scanf("%d %d", &n, &m)!=EOF)
    {

        /*scanf("%d %d", &n, &m);
        if(n==EOF)
        {
            break;
        }//if*/

        cont ++;
        fGrafoVazio(G, n);

        for(int i=0; i < m; i++)
        {
            scanf("%d", &a);
            scanf("%d", &b);

            insereAresta(a, b, G);
            insereAresta(b, a, G);
        }//for

        resultado = bipartido(G);
        if(resultado==1)
        {
            printf("Instancia %d\n", cont);
            printf("sim\n\n");
            /*cout << "Instancia " << cont << endl;
            cout << "sim" << endl << endl;*/
        }else
        {
            printf("Instancia %d\n", cont);
            printf("nao\n\n");
            /*cout << "Instancia " << cont << endl;
            cout << "nao" << endl << endl;*/
        }

    }

    free(G);

    return 0;
}//main()