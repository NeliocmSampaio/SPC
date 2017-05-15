/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matrícula: 2015042150
 * Codigo do Problema: BIT  Problema: Bits Trocados
 *
 * O algoritmo implementa uma solução gulosa, somando cédulas maiores até que, caso se some mais uma,
 * o valor será estourado, e, então soma-se as cédulas de valor imediatamente inferior. Repete-se isso
 * até que o valor seja alcançado.
 *
 * */

#include <iostream>


using namespace std;

int main()
{
    int cnt_50, cnt_10, cnt_5, cnt_1;
    int valor;
    int aux_valor, cnt;

    cnt_1 = 0;
    cnt_5 = 0;
    cnt_10 = 0;
    cnt_50 = 0;
    aux_valor = 0;
    cnt = 0;

    scanf("%d", &valor);

    while(valor != 0)
    {
        while(aux_valor+50 <= valor)
        {
            aux_valor += 50;
            cnt_50++;
        }//while

        while(aux_valor+10 <= valor)
        {
            aux_valor += 10;
            cnt_10++;
        }//while

        while(aux_valor+5 <= valor)
        {
            aux_valor += 5;
            cnt_5++;
        }//while

        while(aux_valor+1 <= valor)
        {
            aux_valor += 1;
            cnt_1++;
        }//while
        cnt++;

        printf("Teste %d\n", cnt);
        printf("%d %d %d %d\n\n", cnt_50, cnt_10, cnt_5, cnt_1);

        cnt_1 = 0;
        cnt_5 = 0;
        cnt_10 = 0;
        cnt_50 = 0;
        aux_valor = 0;

        scanf("%d", &valor);
    }//while

    return 0;
}