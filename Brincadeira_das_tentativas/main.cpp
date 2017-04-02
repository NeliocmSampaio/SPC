//
    //Nome: Nélio Cezar Muniz Sampaio
    //Matricula: 2015042150
    //Codigo do Problema: TENTA     Problema: Brincadeira das Tentativas

    //O algoritmo le um vetor com o número correspondente à figurinha e ordena
    //através do método sort(). Então é usado o método next_permutation() para reordenar
    //o vetor enquanto houverem permutações.
//

#include <iostream>
#include <algorithm>

using namespace std;

void leVetor(int v[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        cin >> v[i];
    }//for
}//leVetor()

void printVetor(int v[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        cout << v[i];
        if(i<tam-1)
            cout << " ";
    }//for
    cout << endl;
}//printVetor()

int main()
{
    int n;
    int v[10];

    cin >> n;

    while(n!=0)
    {
        leVetor(v, n);

        std::sort(v, v+n);

        do{
            printVetor(v, n);
        }while(std::next_permutation(v, v+n));

        cout << endl;
        cin >> n;
    }//while

    return 0;
}
