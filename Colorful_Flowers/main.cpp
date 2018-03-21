/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: 11152    Problema: Colourful Flowers
 *
 * O algoritmo calcula a áre do triangulo através da fórmula de Heron
 * A=sqrt(s(s-a)(s-b)(s-c)), onde a, b e c são os lados do triangulo e
 * s é o semiperímetro s=(a+b+c)/2. Então calcula-se o raio do círculo
 * inscrito r=A/s, e o raio do círculo circunscrito R=(a*b*c)/4A. Calcula-se,
 * então a área dos círculos com a fórmula Ac=PI*r² e subtrai-se de cada um
 * as áreas das formas em seu interior para encontrar a resposta.
 * */

#include <iostream>
#include <cmath>

//# define PI          3.141592653589793238462643383279502884L
const long double PI( acos(-1.0) );

using namespace std;

int main() {

  cout.precision(4);
  cout << fixed;

  long long a, b, c;
  double s, ATriang, r, R;
  double sunFlowers, violets, roses;

  while(cin >> a >> b >> c)
  {
    s = (a+b+c)/2.0;
    ATriang = sqrt(s*(s-a)*(s-b)*(s-c));
    r = ATriang/s;
    R = (a*b*c)/(double)4/ATriang;

    sunFlowers = PI * pow(R, 2) - ATriang;
    roses = PI * pow(r, 2);
    violets = ATriang - roses;

    cout << sunFlowers << " " << violets << " " << roses << endl;
  }//while

  return 0;
}