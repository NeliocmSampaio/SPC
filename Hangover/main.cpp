/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do problema: HANGOVER   Problema: Hangover
 *
 * O algoritmo faz o somatório de de 1/i, para i começando em 2,
 * até que seja maior que c;
 * */

#include <iostream>

using namespace std;

int main() {
  int i= 0;
  double soma, aux, c;
  cin >> c;

  while(c!=0.00)
  {
    soma = 0;
    i=1;

    while(soma<=c)
    {
      aux = 1.0/(i+1);
      soma += aux;
      i++;
    }//while

    cout << i-1 << " card(s)" << endl;
    cin >> c;
  }
  return 0;
}//main()