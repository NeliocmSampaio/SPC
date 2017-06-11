/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 1028 Problema: Figurinhas
 *
 * Utiliza-se o algoritmo de Euclides para calcular o MDC entre
 * os números lidos.
 * */

#include <iostream>

#define loop(i, n) for(int i=0; i<n; i++)

using namespace std;

int mdc(int m, int n)
{
  int r;
  int aux;

  if(n<0) n *= -1;
  if(m<0) m *= -1;

  if(m<n)
  {
    aux = m;
    m = n;
    n = aux;
  }

  r = m%n;
  while(r!=0)
  {
    aux = n;
    n = r;
    m = aux;
    r = m%n;
  }

  return n;

}//mdc()

int main() {
  int n;
  int a, b;

  cin >> n;

  loop(i, n)
  {
    cin >> a >> b;
    cout << mdc(a, b) << endl;
  }//loop

  return 0;
}