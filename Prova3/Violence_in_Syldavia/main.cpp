  #include <iostream>
  #include <cstdio>
  #include <list>
  #include <queue>
  #include <utility>

  #define lp(i, n)  for(int i=1; i<n; i++)

  typedef enum{
    vis, nvis, p   //visitado, não visitado e pilha
  }vState;

  using namespace std;

  class Grafo{
   private:
    int v;
    std::list< std::pair<int, int> > *adj;

    int aux;

   public:
    vState *visitados;

    Grafo(int v)
    {
      this->v = v;
      this->adj = new std::list< std::pair<int, int> >[v+1];
      this->visitados = new vState[v+1];
    }//Grafo()

    void addAresta(int a, int b, int peso)
    {
      this->adj[a].push_back(make_pair(b, peso));
    }//addAresta()

    void printGrafo()
    {
      for(int i=1; i<=this->v; i++)
      {
        std::cout << i;

        std::list<std::pair<int, int> >::iterator it;
        for(it=this->adj[i].begin(); it!=this->adj[i].end(); it++)
        {
          std::cout << " -> " << it->first;
        }//for
        std::cout << endl;
      }//for
    }//printGrafo()

    bool CicleDFS(int u)
    {
      (visitados[u]) = vis;

      std::list<std::pair<int, int> >::iterator it;
      for(it=(this->adj)[u].begin(); it!=(this->adj)[u].end(); it++)
      {
        if(it->first > u )
        {
          if((visitados[it->first])==nvis)
          {
            CicleDFS(it->first);
          }else
          {
            return false;
          }//else
        }else if(it->first == u)
        {
          return false;
        }//else
      }//for

      return true;
    }//CicleDFS()

    void inicializaVisitados(/*vState v[]*/)
    {
      lp(i, this->v+1)
      {
        visitados[i] = nvis;
      }//lp
    }//inicializaVisitados()

    bool haveCicle()
    {
      for(int i=1; i<=this->v; i++)
      {
        this->adj[i].sort();
      }
      bool flag = true;

      //inicializaVisitados(/*visitados*/);

      for(int i=1; i<=this->v; i++)
      {
        inicializaVisitados();
        if(visitados[i]==nvis)
        {
          flag &= CicleDFS(i);
        }//if

      }//lp

      if(!flag) return false;
      return flag;
    }//haveCicle()

    bool DFS(int u)
    {
      std::list<std::pair<int, int> >::iterator it;
      for(it= adj[u].begin(); it!=adj[u].end(); it++)
      {
        if(it->first == aux)
        {
          return true;
        }else{
          DFS(it->first);
        }
      }//for
      return false;
    }

    bool temCiclo()
    {
      for(int i=1; i<=v; i++)
      {
        aux = i;
        if(DFS(i))
        {
          return false;
        }//if
      }//for

      return true;
    }
  };

  int main() {
    int n, m;
    int a, b;
    bool resp;

    while(scanf("%d %d", &n, &m) != EOF)
    {
      Grafo g(n);
      lp(i, m+1)
      {
        scanf("%d %d", &a, &b);

        g.addAresta(a, b, 1);
        g.addAresta(b, a, 1);

      }//lp

      //resp = g.haveCicle();
      resp = !g.temCiclo();

      if(resp)
      {
        printf("Seguro\n");
      }else
      {
        printf("Inseguro\n");
      }

    }//while

    return 0;
  }
