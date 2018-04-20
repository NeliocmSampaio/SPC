#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

void printV(vector<string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

void process(vector<string> v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            if( i!=j )
            {
                
            }
        }
    }
}

int main()
{   
    int n;
    vector<string> v;
    string s;

    scanf("%d", &n);
    while(n!=0)
    {
        while(n--)
        {
            cin >> s;
            v.push_back(s);
        } 

        sort(v.begin(), v.end(), cmp);
        process(v);

        //printV(v);

       scanf("%d", &n);
       //printf("\n");
    }
    return 0;
}