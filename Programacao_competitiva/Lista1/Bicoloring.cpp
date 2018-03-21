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
		adj = new std::vector<int> [v+1];
	}//Graph()

	void add(int a, int b)
	{
		(this->adj)[a].push_back( b );
		(this->adj)[b].push_back( a );		
	}//add()

	bool dfs(int v, int *color, int c)
	{
		color[v] = c;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(color[*it]==0)
			{
				if(dfs(*it, color, 1-c)==false)
				{
					return false;
				}//if
			}else
			{
				if(color[*it] == c )
				{
					return false;
				}//if
			}//else
		}//for

		return true;
	}//dfs()

	bool bicolor()
	{
		int color [ this-> v ];
		int c;
		for(int i=0; i<this->v; i++)
		{
			color[i] = 0;
		}//for

		for(int i=0; i<this->v; i++)
		{
			if(color[i] == 0 )
				if( dfs(i, color, 0) == false )
				{
					return false;
				}
		}

		return true;

		/*color[0] = 1;
		c = 2;
		std::vector<int>::iterator it;
		for(int i=0; i<this->v; i++)
		{
			for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
			{	
				if( color[*it]!=0 )
				{
					if( color[*it] != c )
					{
						return false;
					}//if
				}else color[*it] = c;
			}//for
			c = c==1 ? 2 : 1;
		}//for

		return true;*/
	}//bicolor()

	void print()
	{
		int i;
		int v;

		for( i=0; i<this->v; i++ )
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

	void read()
	{
		int e, a, b;
		scanf("%d", &e);
		for(int i=0; i<e; i++)
		{
			scanf("%d %d", &a, &b);
			this->add(a, b);
		}//for
	}//read()

};//Graph

int main()
{
	int v;

	cin >> v;
	while( v != 0 )
	{
		Graph G(v); 
		G.read();
		//G.print();

		printf( G.bicolor() ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n" );

		cin >> v;
	}//while

	return 0;
}//main()