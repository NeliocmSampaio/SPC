/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: B. Choosing Symbol Pairs
 *
 * O algoritmo percorre a string lida e, para cada letra ja encontrada, soma-se
 * o número de vezes que ela foi encontrada vezes dois à soma total. Soma-se também
 * o número de letras na linha, pois cada uma coincide com ela mesma.
 **/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string linha;
    int cont[300]={0};
    long long soma = 0;

    cin >> linha;
    soma = (int)linha.size();

    for(int i=0; i<(int)linha.size(); i++)
    {
        soma += cont[linha[i]]*2;
        cont[linha[i]]++;
    }//for

    cout << soma;

    return 0;
}