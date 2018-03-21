// Grafos - Verifica se um grafo direcionado tem ciclo

#include <iostream>
#include <list>
#include <stack> // pilha para usar na DFS

using namespace std;

class Grafo
{
	int V; // número de vertices
	list<int> *adj;

public:
	Grafo(int V);
	void adicionarAresta(int v1, int v2);

	// faz uma DFS a partir de um vértice, retorna se achou ciclo ou não
	bool dfs(int v);

	// verifica se o grafo direcionado tem ciclo
	bool temCiclo();
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V+1];
}

void Grafo::adicionarAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}

bool Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V+1], pilha_rec[V+1];

	// inicializa visitados e pilha_rec com false
	for(int i = 0; i <= V; i++)
		visitados[i] = pilha_rec[i] = false;

	// faz uma DFS
	while(true)
	{
		bool achou_vizinho = false;
		list<int>::iterator it;

		if(!visitados[v])
		{
			pilha.push(v);
			visitados[v] = pilha_rec[v] = true;
		}

		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// se o vizinho já está na pilha é porque existe ciclo
			if(pilha_rec[*it])
				return true;
			else if(!visitados[*it])
			{
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if(!achou_vizinho)
		{
			pilha_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha
			if(pilha.empty())
				break;
			v = pilha.top();
		}
		else
			v = *it;
	}

	return false;
}

bool Grafo::temCiclo()
{
	for(int i = 0; i <= V; i++)
	{
		if(dfs(i))
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	int n, m;
	int a, b;
	bool resp;

	while(scanf("%d %d", &n, &m) != EOF)
	{
		Grafo g(n);
		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);

			g.adicionarAresta(a, b);
			//g.adicionarAresta(b, a);

			//g.printGrafo();
			//cout << endl;
		}//lp

		//g.printGrafo();

		resp = !g.temCiclo();

		//g.printGrafo();

		if(resp)
		{
			printf("Seguro\n");
		}else
		{
			printf("Inseguro\n");
		}

	}//while

	return 0;
}