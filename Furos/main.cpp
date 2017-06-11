/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Problema: B. Trace
 *
 * O algoritmo le o raio de todos os cículos e os ordena de forma decrescente.
 * então, a partir do último, soma e subtrai a área dos círculos.
 * */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void printV(vector<pair<int, int>> v)
{
  for(int i=0; i<v.size(); i++)
  {
    cout<<"(" << v[i].first << ", " << v[i].second << "), ";
  }
  cout << endl;

}

double dist(pair<int, int> a, pair<int, int> b)
{
  return pow(a.first-b.first, 2) + pow(a.second-b.second, 2);
}//distancia()

int main() {
  int n;

  cin >> n;
  while(n != 0)
  {
    vector<pair<int, int> > pontos(n);
    for(int i=0; i<n; i++)
    {
      int x, y;
      cin >> x >> y;

      pontos[i] = make_pair(x, y);
    }//for

    vector<double> maiores(n);
    for(int i=0; i<n; i++)
    {
      double maior = -1;
      for(int j=0; j<n; j++)
      {
        if(i!=j)
        {
          if(maior < dist(pontos[i], pontos[j]))
          {
            maior = dist(pontos[i], pontos[j]);
          }//if
        }//if
      }//for
    }//for

    printV(pontos);

    cin >> n;
  }//while

  return 0;
}