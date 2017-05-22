#include <iostream>

using namespace std;
//penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50
int c[] = {1, 5, 10, 25, 50};

void printV(int v[], int t)
{
    for(int i=0; i<t; i++)
    {
        cout << v[i] << " " ;
    }
    cout << endl;
}

int conta(int n)
{
    int m[n+10] = {1};
    for(int i=0; i<5; i++)
    {
        for(int j=c[i]; j<=n; j++)
        {
            //if(j==c[i])
              //  m[j] = 1;
            //else
                m[j] += m[ j - c[i] ];
        }
    }

    printV(m, n+1);
    return m[n];
}

int cont(int n, int m)
{
    int table[n][n];
    for (int i=0; i<n+1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i==0)
            {
                table[i][j] = 1;
            }else if(j==0)
            {
                if(i%c[j]==0)
                {
                    table[i][j] = 1;
                }else
                {
                    table[i][j] = 0;
                }
            }else if(c[j] > i)
            {
                table[i][j] = table[i][j-1];
            }else
            {
                table[i][j] = table[i-c[j]][j] + table[i][j-1];
            }//else
        }//for
    }//for

    return table[n][m-1];
}

int main() {
    int n;
    int ways;

    while(cin >> n)
    {
        //ways = cont(n, 5);
        ways = conta(n);
        if(ways == 1)
            printf("There is only %d way to produce %d cents change.\n", ways, n);
        else
            printf("There are %d ways to produce %d cents change.\n", ways, n);
    }//while
    return 0;
}