#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Graph{
private:
	int v;
	vector < int > * adj;
public:
	Graph(int v)
	{
		this->v = v;
		adj = new std::vector<int> [v+2];
	}//Graph()

	void add(int a, int b)
	{
		(this->adj)[a].push_back( b );
		(this->adj)[b].push_back( a );		
	}//add()

	bool dfs(int v, int *color)
	{
		color[v] = 1;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(color[*it]==0)
			{
				dfs(*it, color);
			}//if
		}//for

		color[v] = 2;
	}//dfs()

	int dfscont()
	{
		int color [ this-> v ];
		int cont = 0;
		for(int i=0; i<=this->v; i++)
		{
			color[i] = 0;
		}//for

		for(int i=1; i<=this->v; i++)
		{
			if(color[i] == 0 )
			{
				dfs(i, color);
				cont++;
			}//if
		}//for

		return cont;
	}//bicolor()

	void print()
	{
		int i;
		int v;

		for( i=1; i<=this->v; i++ )
		{
			printf( "%d", i );

			std::vector< int >::iterator it;
			for( it=(this->adj)[i].begin(); it!=(this->adj)[i].end(); it++)
			{
				v = *it;

				printf( "-> %d", v );
			}//for
			printf( "\n" );
		}//for
	}//print()

	void read(int e)
	{
		int a, b;
		for(int i=0; i<e; i++)
		{
			scanf("%d %d", &a, &b);
			this->add(a, b);
		}//for
	}//read()

};//Graph

int main()
{
	int v, e, cont=1;

	cin >> v >> e;
	while( v != 0 )
	{
		Graph G(v); 
		G.read(e);
		//G.print();

		printf( "Case %d: %d\n", cont, G.dfscont() );
		cont++;

		cin >> v >> e;
	}//while

	return 0;
}//main()