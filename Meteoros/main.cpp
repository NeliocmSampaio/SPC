/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: METEORO    Problema: Meteoros
 *
 * O algoritmo le as coordenadas dos pontos e compara as coordenadas x e y de cada um
 * com as coordenadas dos cantos do retângulo.
 * */

#include <iostream>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  int n;
  int x, y;
  int cont;
  int j;

  cont = 0;
  j = 0;

  cin >> x1 >> y1 >> x2 >> y2;
  while(x1!=0 || x2!=0 || y1!=0 || y2!=0 )
  {
    cin >> n;

    for(int i=0; i<n; i++)
    {
      cin >> x >> y;

      if(x1<=x && x<=x2)
      {
        if(y1>=y && y>=y2)
        {
          cont ++;
        }//if
      }//if
    }//for

    j++;
    cout << "Teste " << j << endl;
    cout << cont << endl << endl;

    cont = 0;
    cin >> x1 >> y1 >> x2 >> y2;
  }//while

  return 0;
}