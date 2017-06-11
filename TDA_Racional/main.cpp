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

#define loop(i, n)  for(int i=0; i<n; i++)
#define leInt(n)    scanf("%d", &n)
#define leChar(n)    scanf("%c", &n)

using namespace std;

void simplifica(int n1, int d1, int n2, int d2, char s, int *n, int *d)
{
  switch (s)
  {
    case '+':
      (*n) = n1*d2 + n2*d1;
      (*d) = d1 * d2;
      break;
    case '-':
      (*n) = n1*d2 - n2*d1;
      (*d) = d1 * d2;
      break;
    case '*':
      (*n) = n1 * n2;
      (*d) = d1 * d2;
      break;
    case '/':
      (*n) = n1 * d2;
      (*d) = n2 * d1;
      break;
    default:
      break;
  }
}//simplifica()

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
  int n1, n2, d1, d2;
  char s1, s, s2;
  int N, D, nSimp, dSimp;
  int maxDC;

  cin >> n;
  setbuf(stdin, NULL);
  setbuf(stdin, NULL);

  loop(i, n)
  {
    scanf("%d %c %d %c %d %c %d", &n1, &s1, &d1, &s, &n2, &s2, &d2);

    simplifica(n1, d1, n2, d2, s, &N, &D);
    maxDC = mdc(N, D);
    nSimp = N/maxDC;
    dSimp = D/maxDC;

    cout << N << "/" << D << " = " << nSimp << "/" << dSimp << endl;
  }//loop

  return 0;
}