/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: CONTAGEM     Problema: Não é Mais um Joguinho Canadense
 *
 * O algoritmo calcula o custo total somando, para cada b da palavra,
 * 2^(número de letras após o b em questão).
 * */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string palavra;
    string::iterator it;
    int cont=1;
    unsigned long pos;
    unsigned long long custo_total;

    while(cin >> palavra)
    {
        custo_total = 0;
        pos =  palavra.find('b');

        while(pos!=-1)
        {
            custo_total += (long long int)pow(2, palavra.length()-(pos+1));

            pos = palavra.find('b', pos+1);
        }//while

        cout << "Palavra " << cont << endl;
        cout << custo_total << endl << endl;

        cont++;

    }//while

    return 0;
}