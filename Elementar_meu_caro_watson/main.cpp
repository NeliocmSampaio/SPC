#include <iostream>

using namespace std;

int bubbleSort(int v[], int tam)
{
    int i;
    int aux, cont=0,local_cont=0;

    while(1)
    {
        local_cont=0;
        for(i=0; i<tam-1; i++)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                cont++;
                local_cont++;
            }//if
        }//for
        if(local_cont==0)
            break;
    }//while
    return cont;
}//bubbleSort()

int contDesordenado(int v[], int t)
{
    int cont = 0;

    for(int i=0; i<t-1; i++)
    {
        if(v[i] > v[i+1])
        {
            cont++;
        }
    }//for

    return cont;
}

void leVetor(int v[], int t)
{
    for(int i=0; i<t; i++)
    {
        scanf("%d", &(v[i]));
    }//for
}//leVetor()

int main() {
    int t;
    int n;

    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        scanf("%d", &n);
        int vet[n];

        leVetor(vet, n);

        printf("%d\n", n - contDesordenado(vet, n));
    }//for

    return 0;
}