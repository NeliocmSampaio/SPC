/*
 * Nome: NÃ©lio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: FATORIAL   Problema: Fatorial
 *
 * O algoritmo calcula o fatorial do número dividindo por 10 sempre que
 * o último dígito é um zero, a multiplicação é calculada mod 100000. Isso é
 * feito para evitar overflow. Para imprimir o primeiro digito, o resultado
 * é impresso mod 10.
 * */

/*

#include <stdio.h>

int main() {

  int cont;
  unsigned long long x, r;

  cont = 1;

  while (scanf("%d", &x) != EOF)
  {
    r = x;

    for(int i=2; i<x; i++)
    {
      r *= i;
      while((r%10)==0)
      {
        r /= 10;
      }

      r %= 100000;
    }//loop

    printf("Instancia %d\n%d\n\n", cont, r%10);

    cont++;
  }

  return 0;
}*/

#include <iostream>

#define loop(i, n) for (int i=1; i<n; i++)

using namespace std;

unsigned long long fat(int x)
{
  unsigned long long f = x;

  for(int i=2; i<x; i++)
  {
    f *= i;
    while(!(f%10))
    {
      f /= 10;
    }

    f = f % 100000;
  }//loop

  return f;

}//fat()

int main() {

  int cont;
  unsigned long long x, r;

  cont = 1;

  while (scanf("%d", &x) != EOF)
  {
    r = x;

    for(int i=2; i<x; i++)
    {
      r *= i;
      while((r%10)==0)
      {
        r /= 10;
      }

      r %= 100000;
    }//loop

    printf("Instancia %d\n%d\n\n", cont, r%10);
    //cout << "Instancia " << cont << endl;
    //cout << r%10 << endl << endl;

    cont++;
  }

  return 0;
}