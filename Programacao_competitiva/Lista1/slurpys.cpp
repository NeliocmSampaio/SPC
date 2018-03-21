#include <stdio.h>
#include <iostream>

using namespace std;

bool isSlump( string word, int i )
{
	int a = i+1;
	if( word[i] == 'D' || word[i] == 'E' )
	{
		if( word[a] == 'F' )
		{
			a++;
			while( word[a] == 'F' )
			{
				a++;
			}//while

			if(  )
		}else return false;
	}else return false;

	return true;
}//isSlump()

bool isSlimp( string word )
{
	return true;
}//isSlimp()

bool isSlurpy(string word )
{
	return true;
}//isSlurpy()

int main()
{
	int n;
	string word;

	scanf( "%d", &n );
	printf( "SLURPYS OUTPUT\n" );

	for( int i=0; i<n; i++)
	{
		cin >> word;

		if( isSlurpy(word) )
			printf( "YES\n");
		else
			printf( "NO\n" );
	}//for

	printf( "END OF OUTPUT\n" );

	return 0;
}//main()