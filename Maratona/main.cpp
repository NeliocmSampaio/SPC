/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matrícula: 2015042150
 * Codigo do Problema: MARAT09  Problema: Maratona
 *
 * O algoritmo, para cada posto de água lido, calcula a distância para o último posto e
 * verifica se a distância é menor ou igual à distância máxima que o atleta pode correr
 * sem beber água. Ao final, se todas as distâncias forem menores e a distância do último
 * posto para o final da maratona for menor que a distância máxima, a resposta é S e N, caso
 * contrário.
 *
 * */

#include <iostream>

using namespace std;

int main() {
    int n, max_dist;
    int dist_ant=0, dist_atual;

    bool flag = true;

    scanf("%d %d", &n, &max_dist);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &dist_atual);

        if(dist_atual - dist_ant > max_dist)
        {
            flag = false;
        }//if

        dist_ant = dist_atual;

    }//for

    if(flag==true && 42195-dist_ant<=max_dist)
    {
        printf("S\n");
    }else
    {
        printf("N\n");
    }//else

    return 0;
}