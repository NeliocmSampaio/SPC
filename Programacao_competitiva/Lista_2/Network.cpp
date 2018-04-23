#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define max 110
#define infinito 100000000


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

    void addList(char s [])
    {
        int a = atoi( strtok(s, " ") ), b;
		char *aux;

		while(true)
		{
			aux = strtok(NULL, " ");
			if(aux==NULL) break;
			b = atoi( aux );

			this->add(a, b);
		}

    }

	void printV(std::vector < int > v)
	{
		for (int i=0; i<v.size(); i++)
		{
			printf("%d: %d\n", i, v[i] );
		}
	}

	void vdfs(int v, int V[], int low[], int parent[], vector<int> * articulating)
	{
		V[v] = ++time;
		low[v] = V[v];

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(V[*it]>0)
			{
				parent[*it] = v;
				vdfs(*it, V, low, parent, articulating);
			}else
			{
				if(V[v] <= low[*it])
				articulating->push_back(v);
			}

			if(V[v] <= low[*it])
				articulating->push_back(v);
			else
				low[v] = low[*it] < low[v] ? low[*it] : low[v];
		}
	}

	int ArticulatingPoints()
	{
		int visited[this->v];
		int low[this->v];
		int parent[this->v];
		std::vector<int> articulating;
		int cont;

		for(int i=0; i<=this->v; i++)
		{
			visited[i] = -1;
			low[i] = infinito;
			parent[i] = -1;
		}//for

		time = 0;
		std::vector<int>::iterator it;
		for(int i=1; i<this->v; i++)
		{
			cont = 0;
			if(visited[i] != -1)
			{
				visited[i] = time++;
				low[i] = visited[i];
			}
			for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
			{
				if(visited[*it] != -1)
				{
					parent[*it] = i;
					vdfs(*it, visited, low, parent, &articulating);
					cont++;
				}
			}

			if(cont >= 2)
				articulating.push_back(i);
		}
		
		printV(articulating);

		return 0;
	}

	int dfs(int v, std::vector<int> * ans, int low[], int visited[])
	{
		visited[v] = time++;
		low[v] = visited[v];
		int child = 0;

		std::vector<int>::iterator it;
		for(it=this->adj[v].begin(); it!=this->adj[v].end(); it++)
		{
			if(visited[*it]==-1)
			{
				child++;
				int m = dfs(*it, ans, low, visited);
				low[v] = low[v] < m ? low[v] : m;
				if(visited[v]<=m && (v!=1 || child>=2))
				{
					(*ans).push_back(v);
				}
			}else{
				low[v] = low[v] < visited[*it] ? low[v] : visited[*it];
			}
		}

		return low[v];
	}

	vector<int> get_art()
	{
		std::vector<int> ans;
		time = 0;
		int low[this->v+10], visited[this->v+10], parent[this->v+10];
		int cont = 0;

		for(int i=1; i<=this->v; i++)
		{
			visited[i] = -1;
			low[i] = infinito;
		}//for

		dfs(v, &ans, low, visited);

		return ans;
	}

	void assignNum(int v)
	{
		
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
    int n;
    char s [210];

    scanf("%d", &n);
    //setbuf(stdin, NULL);
	getchar();

    while( n != 0)
    {
        Graph G(n);
        //scanf("%[^\n]s", s);
		fgets(s, 210, stdin);
		//getchar();
		//setbuf(stdin, NULL);
		//printf("Linha: %s", s);
        while(s[0]!='0')
        {
            G.addList(s);
            //scanf("%[^\n]s", s);
			fgets(s, 210, stdin);
			//getchar();
			//setbuf(stdin, NULL);
			//printf("Linha: %s", s);
			
        }

		//G.print();
		//G.ArticulatingPoints();
		printf("%d\n", G.get_art().size());

        scanf("%d", &n);
		getchar();
        //setbuf(stdin, NULL);
    }

    return 0;
}