#include <iostream>

using namespace std;

typedef struct reta{
  pair<int, int> p1;
  pair<int, int> p2;
}reta;

typedef enum type{
  hor, ver, point
}type;

type tipo(reta r)
{
  if(r.p1.first==r.p2.first && r.p1.second==r.p2.second) //point
  {
    return point;
  }else if(r.p1.first==r.p2.first) //vertical
  {
    return ver;
  }else //horizontal
  {
    return hor;
  }//else
}//tipo()

void processa(reta a, reta b)
{
  //horizontal horizontal
  if(tipo(a)==hor && tipo(b)==hor)
  {
    if(a.p1.second!=b.p1.second)
    {
      cout << "NO" << endl;
    }else if( a.p1.first>b.p1.first && a.p1.first<b.p2.first ||
              b.p1.first>a.p1.first && b.p1.first<a.p2.first)
    {
      cout << "SEGMENT" << endl;
    }else if( a.p1.first==b.p1.first && a.p1.second==b.p1.second ||
        a.p2.first==b.p2.first && a.p2.second==b.p2.second ||
        a.p1.first==b.p2.first && a.p1.second==b.p2.second ||
        a.p2.first==b.p1.first && a.p1.second==b.p1.second)
    {
      cout << "POINT" << endl;
    }else
    {
      cout << "NO" << endl;
    }
  }//if

  //horizontal vertical
  if(tipo(a)==hor && tipo(b)==ver)
  {

  }

  //vertical horizontal
  if(tipo(a)==ver && tipo(b)==hor)
  {

  }

  //vertical vertical
  if(tipo(a)==ver && tipo(b)==ver)
  {

  }
}

bool isNone(reta a, reta b)
{
  if(tipo(a)==ver && tipo(b)==ver)
  {

  }else if(tipo(a)==hor && tipo(b)==hor)
  {

  }//if
}//isNone()

bool isPoint(reta a, reta b)
{
  return false;
}

bool isSeg(reta a, reta b)
{
  return false;
}

int main() {
  int n;
  int x1, x2, y1, y2;
  reta a, b;

  cin >> n;

  for(int i=0; i<n; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    pair<int, int> p1 = make_pair(x1, y1);
    pair<int, int> p2 = make_pair(x2, y2);
    a.p1 = p1;
    a.p2 = p2;

    cin >> x1 >> y1 >> x2 >> y2;
    /*pair<int, int> */p1 = make_pair(x1, y1);
    /*pair<int, int> */p2 = make_pair(x2, y2);
    b.p1 = p1;
    b.p2 = p2;

    cout << "a: " << tipo(a) << endl;
    cout << "b: " << tipo(b) << endl;

    processa(a, b);

    if(isNone(a, b))
    {
      //cout << "NO" << endl;
    }else if(isSeg(a, b))
    {
      //cout << "SEGMENT" << endl;
    }else
    {
      //cout << "POINT" << endl;
    }//else
  }//for

  return 0;
}