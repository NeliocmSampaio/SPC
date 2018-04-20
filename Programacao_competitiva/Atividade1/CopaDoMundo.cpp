#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int t, n;
	string s;
	int pts, spts;
	//int v[10010];

	scanf("%d %d", &t, &n);

	while(t!=0)
	{
		spts=0;
		for(int i=0; i<t; i++)
		{
			cin >> s >> pts;
			spts+=pts;
		}

		printf("%d\n", 3*n-spts);

		scanf("%d %d", &t, &n);
	}

	return 0;
}