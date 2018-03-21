#include <stdio.h>

using namespace std;

int algorithm( int x )
{
	int cont = 1;

	while( x!= 1 )
	{
		cont++;
		if( x%2 != 0 )
			x = x*3 + 1;
		else
			x = x/2;
	}//while

	return cont;
}//algorithm()

int main()
{
	int i, j, k;
	int  maior = 0, x;

	while( scanf( "%d %d", &i, &j) == 2 )
	{
		maior = 0;
		printf( "%d %d ", i, j );
		if( j < i )
		{
			k = i;
			i = j;
			j = k;
		}//if

		for( k=i; k<=j; k++ )
		{
			x = algorithm(k);
			if( x > maior )
			{
				maior = x;
			}//if
		}//for

		printf( "%d\n", maior );
	}//while

	return 0;
}//main()