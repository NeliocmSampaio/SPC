#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, d, aux;
    vector<int> A, D;

    scanf("%d %d", &a, &d);

    while(a!=0)
    {
        for(int i=0; i<a; i++)
        {
            scanf("%d", &aux);
            A.push_back(aux);
        }

        for(int i=0; i<d; i++)
        {
            scanf("%d", &aux);
            D.push_back(aux);
        }

        sort(A.begin(), A.end());
        sort(D.begin(), D.end());

        //printf("A: ");
        //for(int i=0; i<A.size(); i++)
        //{
        //    printf("%d ", A[i]);
        //}
        //printf("\n");

        //printf("D: ");
        //for(int i=0; i<D.size(); i++)
        //{
        //    printf("%d ", D[i]);
        //}
        //printf("\n");

        if(A[0] < D[1])
        {
            printf("Y\n");
        }else if(A[0]==D[0] && A[0]==D[1])
        {
            printf("N\n");
        }else
        {
            printf("N\n");
        }

        A.clear();
        D.clear();
        scanf("%d %d", &a, &d);
    }

    return 0;
}