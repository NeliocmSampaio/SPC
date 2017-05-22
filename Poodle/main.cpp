/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: POODLEMG     Problema: Poodle
 *
 * O Algoritmo calcula o número de o's a ser impresso dividindo
 * o número de resultados pelo número de resultados em uma página.
 * se a divisão não for exata, soma-se um no resultado. Um loop
 * imprime o número de o's de acordo com as restrições.
 **/

#include <iostream>
#include <cstdio>

using namespace std;



int main() {
    int results, resPPage;
    int div;

    cin >> results >> resPPage;

    while(results != 0)
    {
        div = results / resPPage;
        if( results % resPPage != 0)
        {
            div++;
        }//if

        if(div>20)
        {
            div = 20;
        }

        if(div<6)
        {
            printf("Poodle\n");
        }else
        {
            printf("P");
            for(int i=0; i<div-4; i++)
            {
                printf("o");
            }//for
            printf("dle\n");
        }//else

        cin >> results >> resPPage;
    }//while

    return 0;
}