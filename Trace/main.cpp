/*
 * Nome: Nélio Cezar Muniz Sampaio
 * Matricula: 2015042150
 * Problema: B. Trace
 *
 * O algoritmo le o raio de todos os cículos e os ordena de forma decrescente.
 * então, a partir do último, soma e subtrai a área dos círculos.
 * */

#include <iostream>
#include <vector>
#include <algorithm>
//#include <cmath>

# define M_PIl          3.141592653589793238462643383279502884L

using namespace std;

bool compare(int a, int b)
{
  return b<a;
}
/*
void printV(vector<int> v)
{
  for(int i=0; i<v.size(); i++)
  {
    cout << " " << v[i];
  }
  cout << endl;
}*/

int main() {
  int n;
  double area;

  cin >> n;
  std::vector<int> v(n);

  for(int i=0; i<n; i++)
  {
    std::cin >> v[i];
  }//for

  //printV(v);
  std::sort(v.begin(), v.end(), compare);
  //printV(v);

  area = M_PIl * pow(v[0], 2);
  //cout << M_PI << endl;
  for(int i=1; i<n; i+=2)
  {
    area -= M_PIl * pow(v[i], 2);
    if(i<n-1)
      area += M_PIl * pow(v[i+1], 2);
  }//for

  printf("%.10lf\n", area);
  //cout << area << endl;

  return 0;
}