#include <stdio.h>
#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

typedef struct page{
	int f, b;
}page;

typedef struct paper{
	page p1, p2;
}paper;

void printV(paper *v, int t)
{
	for(int i=0; i<t; i++)
	{
		printf("%d\n", i);
		printf("%d: %d %d\n", i+1, v[i].p1.f, v[i].p2.b);
		printf("%d: %d %d\n", i+1, v[i].p2.f, v[i].p1.b);
	}//for
}

int main()
{
	int n, m, aux, i;

	scanf("%d", &n);

	while( n!=0 )
	{
		m = ceil(n/4.0);
		paper v [m];

		aux = 1;
		for( i=0; i<m; i++ )
		{
			v[i].p1.f = aux++;
			v[i].p1.b = aux++;
		}//for

		aux = m*4/2 +1;
		m++;
		while(m--)
		{
			v[m-1].p2.b = i++;
			v[m-1].p2.f = i++;
		}//while

		printV(v, ceil(n/4.0));

		scanf("%d", &n);	
	}

	return 0;
}