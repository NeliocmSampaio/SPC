#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool isLetter( char c )
{
	return (c>=65 && c<=90) || ( c>=97 && c<=122 );
}//isLetter()

bool isVowel( char c )
{
	return c==65 || c==69 || c==73 || c==79 || c==85 || c==97 || c==101 || c==105 || c==111 || c==117;
}//isVowel()

int main()
{
	string s;
	int i;
	char bck;

	while( getline(cin, s) )
	{
		i=0;
		while( i<s.size() )
		{
			while( i<s.size() && !isLetter( s[i] ) )
			{
				printf("%c", s[i]);
				i++;
			}//while

			if( i<s.size() && isVowel(s[i]) )
			{
				while( i<s.size() && isLetter(s[i]) )
				{
					printf( "%c", s[i] );
					i++;
				}
				printf("ay");

				while( i<s.size() && isLetter(s[i]) )
				{
					printf("%c", s[i]);
					i++;
				}
			}else if( i<s.size() )
			{
				bck = s[i];
				i++;
				while( i<s.size() && isLetter(s[i]) )
				{
					printf( "%c", s[i] );
					i++;
				}
				printf("%cay", bck);

				while( i<s.size() && isLetter(s[i]) )
				{
					printf("%c", s[i]);
					i++;
				}//while
			}//if
		}//while
		while( i < s.size() )
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}//while

	return 0;
}