/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 10008        Problema:  What's Cryptanalysis?
 *
 * O algoritmo percorre as linhas de entrada e incrementa, para cada letra, o número de
 * caracteres iguais. Ao final, é rodado o sort com uma função de comparação que ordena
 * primeiro pelo número de ocorrências e, se for igual, pela ordem alfabetica.
 **/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int vet[25] = {0};
vector<pair<char, unsigned long long int>> vet(27);

bool compara(pair<char, unsigned long long int> a, pair<char, unsigned long long int> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }else return a.second > b.second;
}

/*bool operator <(pair<int, unsigned long long int> a, pair<int, unsigned long long int> b)
{
    return a.second>b.second || a.second==b.second && a.first<b.first;
}*/

void zeraVet()
{
    for(int i=0; i<27; i++)
    {
        vet[i].first = i+'A';
        vet[i].second = 0;
    }
}

void processa(string s)
{
    int index;

    for(int i=0; i<s.size(); i++)
    {
        index = toupper(s[i]);
        if(index>='A' && index <= 'Z') {
            vet[index - 'A'].second++;
        }//if
    }//for
}//processa()

void printVet()
{
    for(int i=0; i<27; i++)
    {
        if(vet[i].second!=0)
        {
            printf("%c %llu\n", vet[i].first, vet[i].second);
        }//if
    }//for
}//printVet()

int main() {
    string linha;
    int n;

    zeraVet();

    scanf("%d", &n);
    getline(cin, linha);

    for(int i=0; i<n; i++)
    {
//setbuf(stdin, NULL);
        getline(cin, linha);
//cout << linha << endl;
        processa(linha);
    }//for

    sort(vet.begin(), vet.end(), compara);
    printVet();

    return 0;
}