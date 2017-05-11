//============================================================================
	//Nome: Nélio Cezar Muniz Sampaio
	//Matricula: 2015042150

	//Codigo do problema: IMPEDIDO	Problema: Ele está impedido
	//O Algoritmo armazena em uma estrutura de dados vector as distâncias dos
	//jogadores até a linha do gol. Depois, é utilizado o método sort para
	//ordenar o vetor, e compara-se a distância do atacante mais próximo da
	//linha do gol com a distância do penúltimo defensor, se o atacante estiver
	//mais próximo, ele está impedido.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void leVetor(vector<int> *v, int tam)
{
	int i;
	int x;

	for(i=0; i<tam; i++)
	{
		cin >> x;
		(*v).push_back(x);
		//cout << (*v).at(i) << " ";
	}//for
	//cout << endl;
}//leVetor()

int function_sort(int i, int j)
{
	return i<j;
}//function_sort()

void printVector(vector<int> v, int t)
{
	for(int i=0; i<t; i++)
	{
		cout << v[i] << " ";
	}//for
	cout << endl;
}//printVector()

int estaImpedido(vector<int> v1, vector<int> v2, int t1, int t2)
{
	std::sort(v1.begin(), v1.begin()+t1, function_sort);
	std::sort(v2.begin(), v2.begin()+t2, function_sort);

	//printVector(v1, t1);
	//printVector(v2, t2);

	//cout << v1[0] << endl;
	//cout << v2[1] << endl;
	if(t2==1) return 1;

	if(v1[0]<v2[1])
	{
		//cout << v1[0] << " " << v2[1] << endl;
		return 1;
	}else return 0;

}//estaImpedido()

int main() {

	int a, d;
	vector<int> atacante;
	vector<int> defensor;

	cin >> a >> d;

	while(a!=0 && d!=0)
	{
		leVetor(&atacante, a);
		leVetor(&defensor, d);

		estaImpedido(atacante, defensor, a, d) == 1 ? cout << "Y" <<endl :
				cout << "N" << endl;

        atacante.clear();
        defensor.clear();

		cin >> a >> d;
	}//while

	return 0;
}//main()

