//
// Created by nelio on 13/05/17.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void leMatriz(int mat[][5])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> mat[i][j];
        }//for
    }//for
}//leMatriz()

bool celUp(int i, int j, int mat[][5])
{
    int iAux = i-1;
    int jAux = j;
    if(iAux<0) return false;
    else
    {
        if(mat[iAux][jAux] == 0 || mat[iAux][jAux] == mat[i][j])
        {
            return true;
        }else return false;
    }//else
}

bool celDown(int i, int j, int mat[][5])
{
    int iAux = i+1;
    int jAux = j;
    if(iAux>3) return false;
    else
    {
        if(mat[iAux][jAux] == 0 || mat[iAux][jAux] == mat[i][j])
        {
            return true;
        }else return false;
    }//else
}

bool celRight(int i, int j, int mat[][5])
{
    int iAux = i;
    int jAux = j+1;
    if(jAux>3) return false;
    else
    {
        if(mat[iAux][jAux] == 0 || mat[iAux][jAux] == mat[i][j])
        {
            return true;
        } else return false;
    }//else
}

bool celLeft(int i, int j, int mat[][5])
{
    int iAux = i;
    int jAux = j-1;
    if(jAux<0) return false;
    else
    {
        if(mat[iAux][jAux] == 0 || mat[iAux][jAux] == mat[i][j])
        {
            return true;
        }else return false;
    }//else
}

void printMatriz(int mat[][5])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << mat[i][j] << " ";
        }//for
        cout << endl;
    }//for
}//printMatriz()

void printVector(vector<string> v, int t)
{
    if(v[1]==1)
    {

    }else if(v[3]==1)
    {

    }else if(v[2]==1)
    {

    }else if(v[0]==1)
    {

    }
}

bool compare(string a, string b)
{
    return a[0] < b[0];
}//compare

bool processa(int mat[][5], int v[]/*vector<string> *v*/, int *iV)
{
    bool fUp, fDown, fRight, fLeft;

    (*iV) = 0;

    fUp = false;
    fDown = false;
    fRight = false;
    fLeft = false;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(mat[i][j] == 2048)
            {
                return false;
            }else /*if(fUp && fDown && fRight && fLeft)
            {
                return true;
            }else*/
            {
                if(!fUp && mat[i][j]!=0 && celUp(i, j, mat)) //up
                {
                    v[(*iV)] = 1;
                    //(*v)[*iV] = ("UP");
                    (*iV)++;
                    fUp = true;
                }else if(!fDown && mat[i][j]!=0 && celDown(i, j, mat)) //Down
                {
                    //(*v)[*iV] = ("DOWN");
                    (*iV)++;
                    fDown = true;
                }else if(!fRight && mat[i][j]!=0 && celRight(i, j, mat)) //Right
                {
                    (*v)[*iV] = ("RIGHT");
                    (*iV)++;
                    fRight = true;
                }else if(!fLeft && mat[i][j]!=0 && celLeft(i, j, mat)) //Left
                {
                    (*v)[*iV] = ("LEFT");
                    (*iV)++;
                    fLeft = true;
                }//else
                //printVector(v);
            }//else
        }//for
    }//for

    if(!fUp && !fDown && !fRight && !fLeft)
    {
        return false;
    }else return true;
}//processa()

int main() {
    int n;
    int mat[5][5];
    int tV;
    int vet[5];
    vector <string> v(4);

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        leMatriz(mat);
        //printMatriz(mat);
        if(processa(mat, &vet, &tV))
        {
            //sort(v.begin(), v.begin()+tV, compare);
            printVector(vet, tV);
        } else
        {
            printf("NONE\n");
        }
    }//for

    return 0;
}