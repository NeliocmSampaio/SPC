/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Problema: 11505 - Logo
 *
 * O algoritmo atualiza a posição da tartaruga para cada comando dado
 * somando o deslocamento em cada eixo (multiplicando por sen e cos)
 *ou a rotação da tartaruga mod 360.
 * */


#include <iostream>
#include <math.h>
#include <cstdio>

# define PI          3.141592653589793238462643383279502884L

using namespace std;
int main() {

  int t, n;
  string comando;

  cin >> t;
  for(int i=0; i<t; i++)
  {
    cin >> n;
    double ang, arg;
    double x, y;

    x=0;
    y=0;
    for(int j=0; j<n; j++)
    {
      cin >> comando >> arg;

      switch (comando[0])
      {
        case 'b':
          x -= arg * cos(ang*PI/180);
          y -= arg * sin(ang*PI/180);
          break;
        case 'f':
          x += arg * cos(ang*PI/180);
          y += arg * sin(ang*PI/180);
          break;
        case 'l':
          ang += arg;
          if(ang>=360)
          {
            ang -= 360;
          }//if
          break;
        case 'r':
          ang -= arg;
          if(ang>=360)
          {
            ang += 360;
          }//if
          break;
        default:
          break;
      }

     /* if(comando[0] == 'b')
      {

      }else if(comando[0] == 'f')
      {

      }else if(comando[0]=='l')
      {

      }else
      {

      }//else
*/
    }//for

    double r = sqrt((x*x)+(y*y));
    printf("%.lf\n", r);
  }//for

  return 0;
}