/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: NLOGONIA Problema: Divisão da Nlogônia
 *
 * O algoritmo compara as coordenadas das residências com as coordenadas do
 * ponto divisório e marca duas variáveis onde está localizada. Ao fim, olhando
 * o valor de cada variável, imprime o quadrante correto.
 * */

#include <iostream>
#include <cstdio>

typedef enum{
    norte, sul, adiv
}latitude;

typedef enum{
    leste, oeste, odiv
}longitude;

int main() {
    int k;
    int n, m;
    int x, y;
    latitude la;
    longitude lo;

    scanf("%d", &k);

    while(k!=0)
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<k; i++)
        {
            scanf("%d %d", &x, &y);

            //latitude
            if(y>m)//Norte
            {
                la = norte;
            }else if(y<m)//Sul
            {
                la = sul;
            }else //divisa
            {
                la = adiv;
            }//else

            //longitude
            if(x>n)//leste
            {
                lo = leste;
            }else if(x<n) //oeste
            {
                lo = oeste;
            }else //divisa
            {
                lo = odiv;
            }//else

            if(la==adiv || lo==odiv)
            {
                printf("divisa\n");
            }else if(la==norte && lo==oeste)//Noroeste
            {
                printf("NO\n");
            }else if(la==norte && lo==leste)//Nordeste
            {
                printf("NE\n");
            }else if(la==sul && lo==leste)//Sudeste
            {
                printf("SE\n");
            }else if(la==sul && lo==oeste)
            {
                printf("SO\n");
            }

        }//for
        scanf("%d", &k);
    }//while

    return 0;
}