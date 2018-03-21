/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: BICHO  Problema: Jogo do bicho
 *
 * O algoritmo aplica a operação de módulo para descobrir se os últimos algarismos
 * são iguais. Para verificar se se os dois ultimos dígitos são do mesmo grupo,
 * aplica-se uma divisão inteira, então compara-se o resultado.
 * */

#include <iostream>

using namespace std;

int algarismo(int *x)
{
    if (*x == 0) return -1;
    int res = *x % 10;
    *x = *x /10;
    return res;
}//algarismo()

bool compara(int n, int m)
{
  int aux;
  if(n==0) n = 100;
  if(m==0) m = 100;

  if(n<m)
  {
    aux = m;
    m = n;
    n = aux;
  }

  if(n%4==0)
  {
    return (n/4) == ((m/4)+1);
  }else
  {
    return ((n)/4) == ((m/4));
  }
}

int numsIguais(int n, int m)
{
    //int contAlg[11]= {0};
    int cont, i;
    int algN, algM;

   // while(algarismo(&n)!=-1)

    cont = 0;
    if(n%10000 == m%10000)
    {
      cont = 4;
    }else if(n%1000 == m%1000)
    {
      cont = 3;
    }else if(n%100 == m%100)
    {
      cont = 2;
    }else if( compara(n%100, m%100) )
    {
      cont = 1;
    }

    /*i=0;
    algN = algarismo(&n);
    algM = algarismo(&m);
    while( algN == algM && i<=4 *//*&& algN!=-1 && algM!=-1*//* )
    {
        cont ++;

        algN = algarismo(&n);
        algM = algarismo(&m);
        i++;
    }//while*/
    return cont;
}//numsIguais()

int main() {
    double v;
    int m, n;
    int iguais;

    cin >> v >> n >> m;
    while(v != 0)
    {
        /*cout << "1000:"<< n%1000 << " " << m%1000 << endl;
        cout << "100:"<< n%100 << " " << m%100 << endl;
        cout << "10:"<< n%10 << " " << m%10 << endl;
        cout << "1:"<< n%1 << " " << m%1 << endl;*/
        iguais = numsIguais(n, m);
        switch (iguais)
        {
            case 0:
                printf("%.2lf\n", v*0);
                break;
            case 1:
                printf("%.2lf\n", v*16);
                break;
            case 2:
                printf("%.2lf\n", v*50);
                break;
            case 3:
                printf("%.2lf\n", v*500);
                break;
            case 4:
                printf("%.2lf\n", v*3000);
                break;
            default:
                break;
        }

        cin >> v >> n >> m;
    }

    return 0;
}