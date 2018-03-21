/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 1022  Problema: TDA Racional
 *
 * O algoritmo calcula o resultado simplificado através do algoritmo de Euclides
 * para calcular o mdc entre o numerador e o denominador. Então dividi-se ambos
 * pelo mdc e tem-se a fração simplificada.
 * */

#include <iostream>
#include <cmath>

#define loop(i, n)  for(int i=0; i<n; i++)
#define CRIVOTAM 10000000
using namespace std;

long long primes[CRIVOTAM] = {0};
long long seg[CRIVOTAM] = {0};

void crivoSegmentado(long long crivo[], int n, int m)
{
  loop(i, CRIVOTAM)
  {
    int primo = crivo[i]*floor(m/crivo[i]);
    if(primo < m) primo += crivo[i];

    if(crivo[i] >= n) break;
    if(crivo[i] == primo) continue;

    for(int j=primo; j<=n; j+=crivo[i]) seg[j-m] = 1;
  }//loop
}//crivoSegmentado()

void crivo()
{
  loop(i, CRIVOTAM)
  {
    if(primes[i] == 0)
    for(int j=i+i; j<100000; j+=i)
    {
      primes[i] = 1;
    }//for
  }//loop
}//crivo()

void printPrimos(int n, int m)
{
  for(int i=n; i<=m; i++)
  {
    if(primes[i]==0)
    {
      cout << primes[i] << endl;
    }//if
  }//for
}//printPrimos()

int main() {
  int n;
  int a, b;

  crivo();

  cin >> n;

  loop(i, n)
  {
    scanf("%d %d", &a, &b);

    printPrimos(a, b);

  }//loop

  return 0;
}