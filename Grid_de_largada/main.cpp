/*
    //Nome: Nélio Cezar Muniz Sampaio
    //Matricula: 2015042150
    //Codigo do problema: 1228  Problema: Grid de largada

    //O algoritmo consiste em criar um vetor auxiliar que guarda a posição do
    //i-ésimo carro da chegada na largada (mapa(chegada[i]) = posição de
    //chegada[i] na largada). Então, é executado o bubble sort e conta-se o
    //número de trocas, que é o número mínimo de ultrapassagens.

*/

#include <iostream>

using namespace std;

void leVetor(int v[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cin >> v[i];
    }//for
}//leVetor()

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

int mapa(int x, int v[], int tam)
{
    int i = 0;
    while(1)
    {
        if(v[i] == x || i == tam)
        {
            return i;
        }//if
        i++;
    }//while
    return -1;
}//mapa()

void mapeia(int v1[], int v2[], int aux[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        aux[i] = mapa(v1[i], v2, n);
    }//for
}//mapeia()

void printVetor(int v[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << v[i] << " ";
    }//for
    cout << endl;
}//printVetor()

int main()
{
    int largada[30];
    int chegada[30];
    int auxiliar[30];
    int n;

    while(cin >> n)
    {
        leVetor(largada, n);
        leVetor(chegada, n);

        mapeia(chegada, largada, auxiliar, n);
        //printVetor(auxiliar, n);

        cout << bubbleSort(auxiliar, n) << endl;
        //printVetor(auxiliar, n);
    }//while
    return 0;
}//main
