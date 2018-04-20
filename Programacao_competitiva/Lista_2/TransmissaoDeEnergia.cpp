#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

class Graph{
private:
	int v;
	std::vector<int> * adj;
	int time;
public:
	Graph(int v)
	{
		this->v = v;
		this->adj = new std::vector<int> [v];
	}

	void add(int a, int b)
	{
		this->adj[a-1].push_back(b-1);
		this->adj[b-1].push_back(a-1);
	}

	void read(int m)
	{
		int a, b;
		for(int i=0; i<m; i++)
		{
			scanf("%d %d", &a, &b);
			add(a, b);
		}//for
	}//read()

	void printV(std::vector < std::pair<int, int> > v)
	{
		for (int i=0; i<v.size(); i++)
		{
			printf("%d: %d, %d\n", i, v[i].first, v[i].second);
		}
	}

	void vdfs(int v, int * V)
	{
		V[v] = 1;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(V[*it]==0)
			{
				vdfs(*it, V);
			}
		}
		V[v] = 2;
	}

	bool dfs()
	{
		int V[this->v];
		int cont = 0;
		for(int i=0; i<this->v; i++)
			V[i] = 0;

		for(int i=0; i<this->v; i++)
		{
			if(V[i]==0)
			{
				if(cont !=0 )
					return false;
				cont++;
				vdfs( i, V );
			}
		}

		return true;
	}

	bool connected()
	{
		return dfs();
	}

	void print()
	{
		std::vector<int>::iterator it;
		for(int i=0; i<this->v; i++)
		{
			printf("%d : ", i+1);
			for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
			{
				printf("%d ", (*it)+1);
			}
			printf("\n");
		}
	}

};

int main()
{
	int e, l ;
	int cont=1;

	scanf("%d %d", &e, &l);
	while( e!=0)
	{
		Graph G(e);

		G.read(l);

		printf("Teste %d\n", cont);
		printf(G.connected() ? "normal\n" : "falha\n");
		printf("\n");

		cont++;

		scanf("%d %d", &e, &l);
	}

	return 0;
}//main()