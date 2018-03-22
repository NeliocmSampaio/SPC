#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int s, aux;

	int x = 0, y = 0;

	scanf("%d", &n);
	while( n!=0 )
	{
		//printf("%d\n", n);
		s = ceil( sqrt(n) );
		aux = s * s;

		//printf("%d %d\n", s, aux);
		if( aux%2 == 0 )
		{
			if(aux - n < s)
			{
				x = s;
				y = (aux - n) + 1;
			}else
			{
				y = s;
				x = n - pow (s-1, 2);
			}//else
		}else
		{
			if( aux - n < s )
			{
				y = s;
				x = (aux - n) + 1;
			}else
			{
				x = s;
				y = n - pow(s-1, 2);
			}//else
		}//else

		printf("%d %d\n", x, y);

		scanf("%d", &n);
	}//while

	return 0;
}//main()