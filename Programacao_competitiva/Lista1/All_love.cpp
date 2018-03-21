#include <stdio.h>
#include <iostream>

using namespace std;

int bti(string s)
{
	int x = 0;

	for( int i=0; i<s.size(); i++ )
	{
		if( s[i] == '1' )
		{
			//cout << '1' << endl;
			x = x << 1;
			x |= 1;
		}else
		{
			//cout << '0' << endl;
			x = x << 1;
		}
		//cout << x << endl;
	}//for

	return x;
}//bti()

bool divisor2(int a, int b)
{
	int x;
	x = a<b ? a : b;

	while( a%x !=0 || b%x != 0 )
		x--;

	return x==1 ? false : true;
}//multiple()

int divisor( int a, int b )
{
	if(b==0)
		return a;
	else return divisor(b, a%b);
}//divisor()

int main()
{
	int n, a, b;
	string s1, s2;
	int cont = 1;

	while ( cin >> n )
	{
		for(int i=0; i<n; i++)
		{
			cin >> s1 >> s2;
			a = bti(s1);
			b = bti(s2);

			//cout << a << " " << b << endl;

			printf("Pair #%d: ", cont);
			printf( divisor(a, b)!=1 ? "All you need is love!\n" : "Love is not all you need!\n");
			cont ++;
		}//for

	}//while

	return 0;
}//main()