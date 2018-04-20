#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>


using namespace std;

int c[510];
vector<int> stack(510);
int tempo[510];
int menor[510];
int t;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

typedef struct Graph{
	int v;
	int m[510][510];
}Graph;

void init(Graph * G, int nv)
{
	G->v = nv;
	for(int i=1; i<=G->v; i++)
		for(int j=1; j<=G->v; j++)
			G->m[i][j] = 0;
}

void add(Graph *G, int a, int b, int p)
{
	G->m[a][b] = p;
}

void transpose(Graph G, Graph * T)
{
	for(int i=1; i<=G.v; i++)
		for(int j=1; j<=G.v; j++)
			if( G.m[i][j]>0 )
			{
				T->m[j][i] = G.m[i][j];
			}
}

void vdfs(Graph G, int v, vector< pair<int, int> > * time)
{
	//printf("teste\n");
	c[v] = 1;
	t++;

	for(int i=1; i<=G.v; i++)
	{
		for(int j=1; j<=G.v; j++)
		{
			if((G.m)[i][j] != 0)
			{
				if( c[j] == 0)
				{
					vdfs(G, j, time);
				}
			}
		}
	}

	printf("%d\n", v);

	if(time!=NULL)
	{
		(*time)[v].second = t;
		printf("TT %d = %d\n", v, t);
	}
	t++;
	c[v] = 2;
}

void dfs(Graph G, vector <pair<int, int> > * time)
{
	for(int i=1; i<=G.v; i++)
	{
		c[i] = 0;
		if(time!=NULL)
		{
			(*time)[i].first = i;
			(*time)[i].second = 0;
		}
	}

	for(int i=1; i<=G.v; i++)
	{
		if(c[i]==0)
		{
			vdfs(G, i, time);
		}
	}

}

void  printv(vector<pair<int, int> > v)
{
	for(int i=0; i<v.size(); i++)
	{
		printf("(%d, %d), ", v[i].first, v[i].second );
	}
}

void CFC(Graph G)
{
	Graph T;
	int t = 0;
	//int time[510];
	vector <pair< int,int> > time(510);

	//init(&T, G.v);

	printf("teste\n");
	dfs(G, &time);
	printf("teste\n");

	printv(time);
	sort(time.begin(), time.end(), comp);
	printv(time);

	transpose(G, &T);

	dfs(T, NULL);
}

void print(Graph G)
{
	for (int i=1; i<=G.v; i++)
	{
		printf("%d ->", i);
		for(int j=1; j<=G.v; j++)
		{
			if(G.m[i][j] != 0)
			{
				printf("(%d, %d), ", j, G.m[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	Graph G, T;
 	//int time[510];
 	vector <pair<int, int> > time(510);

	init(&G, 4);
	add(&G, 1, 2, 5);
	add(&G, 2, 1, 10);
	add(&G, 3, 4, 8);
	add(&G, 4, 3, 7);
	add(&G, 2, 3, 6);

	init(&T, G.v);
	//transpose(G, &T);

	print(G);
	CFC(G);
	//dfs(G, &time);

	return 0;
}