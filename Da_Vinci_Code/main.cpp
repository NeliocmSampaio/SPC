#include <iostream>

using namespace std;

int fibonacci[50];

void calculaF()
{
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    for(int i=3; i<46; i++)
    {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }//for
}//calculaF()

int fib(int n)
{
    return fibonacci[n];
}//fib()

int fib_1(int n)
{
    for(int i=1; i<46; i++)
    {
        if(fibonacci[i]==n)
            return i;
    }//for
    return -1;
}

void decode(int nums[], int t, string s)
{
    char out[110];
    int pos, mpos=-1;
    int nP = 0;

    for(int i=0; i<s.size(); i++)
    {
        out[i] = ' ';
    }

    for(int i=0; i<t; i++)
    {
        /*
         * erro
         *
         * colocar para iterar para os números e, qnd acabar os chars da string,colocar espaço
         * */

        pos = fib_1(nums[nP]);
        if(s[i]>='A' && s[i]<='Z' && pos!=-1)
        {
            pos = fib_1(nums[nP]);
            if(pos>mpos)
                mpos = pos;
            out[pos-1] = s[i];
            nP++;
        }

    }//for

    out[mpos] = '\0';
    cout << out << endl;
}

int main() {
    int n, f;
    string s;

    calculaF();

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &f);
        int nums[f+1];
        for(int j=0; j<f; j++)
        {
            cin >> nums[j];
        }//for
        //cin >> s;
        getline(cin, s);
        getline(cin, s);

        decode(nums, f, s);

    }//for

    return 0;
}