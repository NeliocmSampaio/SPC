/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: PARPROX      Problema: Pontos
 *
 * O algoritmo compara a distância para todos os pontos lidos e guarda a menor.
 * */

#include <iostream>
#include <cstdio>
#include <cmath>

//#define     ponto           std::pair<int, int>
#define     loop(i, n)      for(int i=0; i<n; i++)
//#define     lp(i, j, n)   for(int i=j; i<n; i++)

typedef struct ponto{
    int x, y;
}ponto;

double distancia(ponto a, ponto b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}//distancia()

int main() {
    int n;
    int x, y;
    double menor, d;

    menor = 9999999999999999;

    scanf("%d", &n);

    ponto v[n];

    loop(i, n)
    {
        std::cin >> x >> y;
        v[i].x = x;
        v[i].y = y;
    }//loop

    loop(i, n)
    {
        for(int j=i+1; j<n; j++)
        {
            d = distancia(v[i], v[j]);

            if(d<menor)
                menor = d;
        }//loop
    }//loop

    printf("%.3lf\n", menor);

    return 0;
}