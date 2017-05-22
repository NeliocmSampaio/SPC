/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: ENCOTEL      Problema: Encontre o telefone
 *
 * O algoritmo percorre todos os caracteres da expressão e, caso seja uma
 * letra maiúscula, decodifica de acordo com a tabela. A decodificação dos
 * caracteres é feita de acordo com o intervalo em que ele está, retornando
 * o número correspondente.
 **/

#include <iostream>
#include <cstdio>

using namespace std;

int decode(char c)
{
    if(c<=67)
    {
        return 2;
    }else if(c<=70)
    {
        return 3;
    }else if(c<=73)
    {
        return 4;
    }else if(c<=76)
    {
        return 5;
    }else if(c<=79)
    {
        return 6;
    }else if(c<=83)
    {
        return 7;
    }else if(c<=86)
    {
        return 8;
    }else
    {
        return 9;
    }//else
}

void printNumber(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        //printf("%d", s[i]);
        if(s[i]>=65 && s[i]<=90)
        {
            cout << decode(s[i]);
        }else
        {
            cout << s[i];
        }//else
    }//for
    cout << endl;
}

int main() {
    string expressao;

    while (cin >> expressao)
    {
        //cout << expressao << endl;
        printNumber(expressao);
    }

    return 0;
}