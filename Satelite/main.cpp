/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 10221  Problema: Satellites
 *
 * O algoritmo converte o angulo para graus quando esse é dado em minutos e,
 * dps, converte para radianos durante os calculos fazendo A=(PI*ang)/180.
 * Encontra-se então o raio da circunferência fazendo r=s+RAIODATERRA. Assim
 * calcula-se C= (s-s*cos(A)) / cos( (PI-A)*0.5 ).
 * */

#include <iostream>
#include <cmath>

#define RAIO          6440.0
//# define  PI          3.141592653589793238462643383279502884L
const long double PI( acos(-1.0) );

using namespace std;

int main() {

  cout.precision(6);  //Determina o npumero máximo de digitos ao imprimir um float
  cout << fixed;      //Fixa o número de casas decimais ao imprimir um float.

  long double s, A, C, ang;
  string str;

  while(cin >> s >> ang >> str)
  {
    if(str=="min") {
      ang = ang / 60.0;
    }//if

      if(ang>180) ang = 360-ang;

      s = s+RAIO;
      A = s*(ang*PI/180.0);
      C = (s- s*cos(ang*PI/180.0) ) / cos( ( PI-(ang*PI/180.0) )*0.5 );

      cout << A << " " << C << endl;
  }//while

  return 0;
}