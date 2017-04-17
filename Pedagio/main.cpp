/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: PEDAGIO      Problema: Pedágio
 *
 * O algoritmo gera um grafo com as cidades como vértices e as estradas como
 * arestas. Calcula-se então a distância mínima da origem para todas as cidades
 * com uma busca em largura, e imprime as cidades cuja distância é menor que o
 * pedágio máximo.
 * */

#include <iostream>

#define INFINITE 3000

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

int proxAdjNVisitado(TGrafo *G, int *cores, int linha, int coluna)
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

    prox = proxAdjNVisitado(G, cores, vertice, 1);
    while(prox!=0)
    {
        dfs(G, cores, cont, prox);

        prox = proxAdjNVisitado(G, cores, vertice, prox + 1);
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

void setaVetor(int v[], int tam, int val)
{
    for(int i=0; i<=tam; i++)
    {
        v[i] = val;
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

int proxAdj(TGrafo *G, int linha, int coluna)
{
    for(int i=coluna; i<=G->v; i++)
    {
        if((G->mat)[linha][i] != 0)
            return i;
    }//for
    return 0;
}//proxAdj()

int bfs(TGrafo *G, int cores[], int cBipartido[], int vertice, int *flag, TFila *f)
{
    //cout << vertice << endl;
    int adj;
    int prox;
    cores[vertice] = 1;

    //pinta vertices adjacentes e enfileira
    adj = proxAdjNVisitado(G, cores, vertice, 1);
    while(adj!=0) {
        //efileira
        if (cores[adj] == 0) {
            cores[adj] = 2;
            enfileira(f, adj);
        }
        adj = proxAdjNVisitado(G, cores, vertice, adj + 1);
    }

    adj = proxAdj(G, vertice, 1);
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
        adj = proxAdj(G, vertice, adj + 1);
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

void bfsDistancia(TGrafo *G, int cores[], int vertice,
                 int *flag, int distancias[], TFila *f)
{
    int adj;
    int prox;
    cores[vertice] = 1;

    //enfileira
    adj = proxAdjNVisitado(G, cores, vertice, 1);
    while(adj!=0) {
        //enfileira
        if (cores[adj] == 0) {
            cores[adj] = 2;
            enfileira(f, adj);
        }
        adj = proxAdjNVisitado(G, cores, vertice, adj + 1);
    }//while

    adj=proxAdj(G, vertice, 1);
    while(adj!=0)
    {
        if((distancias[adj]>distancias[vertice]+1) && (distancias[adj]!=0))
        {
            distancias[adj] = distancias[vertice]+1;
        }//if

        adj=proxAdj(G, vertice, adj+1);
    }//while

    cores[vertice] = 3;
    prox = desenfileira(f);
    if(prox!=0)
        bfsDistancia(G, cores, prox, flag, distancias, f);
}//bfsDistancias()

void printDistancias(int v[], int tam, int p, int inicial)
{
    int flag = 0;
    for(int i=1; i<=tam; i++)
    {
        if((v[i]<=p)&&(i!=inicial))
        {
            if(flag==1)
            {
                //printf(" ");
                cout << " ";
            }//if
            flag=1;
            //printf("%d", i);
            cout << i;
        }//if
    }//for
    cout << endl;
}//printDistancias()

void calculaDistancias(TGrafo *G, int inicial, int distancias[])
{
    int cores[60]={0};
    int flag = 0;
    int resultado=1;
    TFila *f = (TFila*) malloc(sizeof(TFila));
    setaVetor(distancias, G->v, INFINITE);
    distancias[inicial] = 0;

    fFilaVazia(f);
    bfsDistancia(G, cores, inicial, &flag, distancias,  f);

    free(f);
}

int main()
{
    TGrafo *G = (TGrafo*) malloc(sizeof(TGrafo));

    int distancias[60];
    int c, e, l, p;
    int cont=0;
    int a, b;

    cin >> c >> e >> l >> p;

    while(c!=0)
    {
        cont ++;
        fGrafoVazio(G, c);

        for(int i=0; i < e; i++)
        {
            scanf("%d", &a);
            scanf("%d", &b);

            insereAresta(a, b, G);
            insereAresta(b, a, G);
        }//for

        //printGrafo(G);
        calculaDistancias(G, l, distancias);
        cout << "Teste " << cont << endl;
        printDistancias(distancias, c, p, l);
        cout << endl;

        cin >> c >> e >> l >> p;
    }

    free(G);

    return 0;
}//main()