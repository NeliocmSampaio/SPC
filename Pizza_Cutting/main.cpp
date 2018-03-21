/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 10079 Problema: Pizza Cutting
 *
 * O algoritmo calcula o número de pedaçõs através da fórmula
 * (n*(n+1)/2)+1.
 * */

#include <iostream>
#include <cmath>

using namespace std;
int main() {

  long long n;

  cin >> n;
  while(n>=0)
  {
    cout << (n*(n+1)/2)+1 << endl;
    cin >> n;
  }

  return 0;
}