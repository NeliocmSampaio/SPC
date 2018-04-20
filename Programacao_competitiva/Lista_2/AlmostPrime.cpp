#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

const int LMT = 1e6;
bool siege[LMT+1];
vector<long long> primePower;

bool factors(int n)
{
	if(n==1) return false;

	vector<int> f;
	int a = -1;
	for(int x=2; x*x<=n; x++)
	{
		while(n%x==0)
		{
			if(a==-1)
				a = x;
			else if(a!=x)
				return false;
			n /= x;
		}
	}
	
	if( (n>1 && a!=n) || a==-1)
		return false;

	return true;
}

bool prime(int n)
{
	if(n<2) return false;
	for(int x=2; x*x<=n; x++)
	{
		if(n%x==0) return false;
	}
	return true;
}

/*
	Calcula o crivo e as potências os primos.
*/
void siegePow(int n)
{
	for(long long i=2; i<=n; i++)
		siege[i] = 1;

	siege[0] = siege[1] = 0;
	for(int i=2; i<=n; i++)
	{
		if(siege[i] != 0 )
		{
			for(int j=2*i; j<=n; j+=i)
			{
				siege[j] = 0;
			}

			for(long long pow=(long long)i*i; pow<=(long long)LMT*LMT; pow*=i)
			{
				primePower.push_back(pow);
			}//for
		}//if
	}//for
}//siegePow()

int main()
{
	int n;
	long long s, f;

	siegePow(LMT);
	sort(primePower.begin(), primePower.end());

	scanf("%d", &n);
	for(int j=0; j<n; j++)
	{
		scanf("%lld %lld", &s, &f);
		//printf("%lld %lld\n", s, f);

		int a = lower_bound(primePower.begin(), primePower.end(), s) - primePower.begin();
		int b = lower_bound(primePower.begin(), primePower.end(), f) - primePower.begin();
		b += binary_search(primePower.begin(), primePower.end(), f);
		
		printf("%d\n", b - a);
	}
}