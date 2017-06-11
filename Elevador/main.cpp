/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Codigo do Problema: ELEVADOR   Problema: Elevador
 *
 * O algoritmo Verifica se algum dos cilindros possui o diametro maior que a largura ou comprimento do elevador.
 * Depois, calcula se a diferença entre a largura e o comprimento e a soma dos raios ao quadrado é menor que a
 * soma dos raios. Caso seja menor, retorna falso(N), senão retorna verdadeiro (S).
 * */

#include <iostream>
using namespace std;

bool processa(int l, int c, int r1, int r2)
{
  int dx = l-(r2+r1), dy = c-(r2+r1);
  int distancia, menorDistancia;
  distancia = dx*dx + dy*dy;
  menorDistancia = r1+r2;

  if((2*r1>l || 2*r1>c) || (2*r2>l || 2*r2>c) || (distancia<menorDistancia*menorDistancia))
    return false;
  else return true;
}//processa()

int main() {
  int l, c, r1, r2;

  cin >> l >> c >> r1 >> r2;
  while(l!=0)
  {
    if(processa(l, c, r1, r2))
    {
      cout << "S" << endl;
    }else
      cout << "N" << endl;

    cin >> l >> c >> r1 >> r2;
  }//while

  return 0;
}