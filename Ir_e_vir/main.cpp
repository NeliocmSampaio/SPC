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

int proxVertice(TGrafo *G, int cores[], int atual, int *linha, int *coluna)
{
    cout << "debug proxVertice " << atual << endl;
    for(int i=0; i<=G->v; i++)
        if((G->mat)[atual][i]!=0)
        {
            if(cores[i]==0)
            {
                cout << "i=" << i << endl;
                return i;
            }
        }
    return -1;
    /*for(int i=atual; i<G->v; i++)
    {
        for(int j=0; j<G->v; j++)
        {
            if((G->mat)[i][j]!=0)
                if(cores[j]==0)
                {
                    *linha = i;
                    *coluna = j;
                    return 1;
                }//if
        }//for
        return 0;
    }//for*/
}//proxVertice()

void dfs(TGrafo *G, int cores[], int *cont, int vertice)
{
    int prox, auxVertice=vertice, flag=0;
    cores[vertice] = 1;
    cont ++;

    cout << "debug dfs " << vertice << endl;
    getchar();
    getchar();
    while(1)
    {
        prox = proxVertice(G, cores, auxVertice, NULL, NULL);
        cout << "prox=" << prox << endl;
        if(prox!=-1)
            break;
        else auxVertice++;
        if(auxVertice > G->v)
            flag=1;
    }//while

    if(flag!=1)
    {
        dfs(G, cores, cont, auxVertice);
    }
    cores[vertice] = 2;
}

char conectado(TGrafo *G)
{
    int cores[2010] = {0};
    int cont=0;
    int vertice = 1;

    //cout << "debug 2" << endl;
    dfs(G, cores, &cont, vertice);

    if(cont==G->v)
        return 1;
    else return 0;
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