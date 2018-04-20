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

	void add(int a, int b, int p)
	{
		this->adj[a-1].push_back(b-1);
		if(p==2)
			this->adj[b-1].push_back(a-1);
	}

	void read(int m)
	{
		int a, b, p;
		for(int i=0; i<m; i++)
		{
			scanf("%d %d %d", &a, &b, &p);
			add(a, b, p);
		}//for
	}//read()

	void transpose(Graph T)
	{
		std::vector<int>::iterator it;
		for(int i=0; i<this->v; i++)
		{
			for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
			{
				//printf("%d %d\n", i, *it);
				T.add( (*it)+1, i+1, 1);
			}
		}
	}

	void vdfs(int v, std::vector<std::pair<int, int> > * ET, int * V)
	{
		time++;
		//printf("%d ", v);
		V[v] = 1;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(V[*it]==0)
			{
				vdfs(*it, ET, V);
			}
		}

		//printf("time: %d %d\n", v, time);
		(*ET)[v].first = time;
		time++;
		V[v] = 2;
	}

	void dfs(std::vector<std::pair<int, int> > * ET)
	{
		time = 0;
		int V[this->v];
		for(int i=0; i<this->v; i++)
			V[i] = 0;

		//printf("DFS:\n");
		for(int i=0; i<this->v; i++)
		{
			if(V[i]==0)
			{
				vdfs( i, ET, V );
			}//if
		}
		//printf("\nend DFS;\n");
	}

	void Tvdfs ( int v, std::vector<std::pair<int, int> > * ET, int V[])
	{
		//printf("%d ", v);
		V[v] = 1;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(V[*it]==0)
			{
				Tvdfs( *it, ET, V );
			}
		}

		V[v] = 2;
	}

	int Tdfs(std::vector<std::pair<int, int> > * ET)
	{
		int V[this->v];
		int c=0;
		for(int i=0; i<this->v; i++)
			V[i] = 0;

		//printf("CFC:\n");
		for(int i=0; i<this->v; i++)
		{
			//printf("\nET[%d] = %d, %d ",i, (*ET)[i].first, (*ET)[i].second);
			if( V[(*ET)[i].second]==0 )
			{
				//printf("\n%d: \n", (*ET)[i].first);
				Tvdfs((*ET)[i].second, ET, V);
				c++;
			}
		}
		//printf("\nend CFC\n");

		return c;
	}

	void printV(std::vector < std::pair<int, int> > v)
	{
		for (int i=0; i<v.size(); i++)
		{
			printf("%d: %d, %d\n", i, v[i].first, v[i].second);
		}
	}

	int CFC()
	{
		//printf("auto\n");
		std::vector<std::pair<int, int> > ET (this->v);
		Graph T(this->v);
		for(int i=0; i<this->v; i++)
		{
			ET[i].first=0;
			ET[i].second=i;
		}

		this->dfs(&ET);
		std::sort( ET.begin(), ET.begin()+this->v, comp );
		//printV(ET);
		this->transpose(T);
		//T.print();
		return T.Tdfs(&ET);
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
	int n, m ;

	scanf("%d %d", &n, &m);
	while( n!=0)
	{
		Graph G(n);

		G.read(m);

		//printf("\n");
		//G.print();
		//printf("\n");
		int nc = G.CFC();
		//printf("%d\n", nc);
		printf(nc==1 ? "1\n" : "0\n" );

		scanf("%d %d", &n, &m);
	}

	return 0;
}//main()