#include <iostream>
#include <list>
#include <utility>
#include <queue>

class Graph{
private:
    int v;
    std::list<std::pair<int, int>> *adj;
    std::list<int> *parent;

public:
    void init(int v){
        this->v = v;
        adj = new std::list<std::pair<int , int>> [v+1];
        parent = new std::list<int> [v+1];
    }//init()

    void addAresta(int v1, int v2, int p)
    {
        adj[v1].push_back(std::make_pair(v2, p));
    }//addAresta()

    void leGrafo(int inicio){
        int v1, v2, p;
        for(int i=inicio; i<this->v+inicio; i++)
        {
            std::cin >> v1 >> v2 >> p;
            this->addAresta(v1, v2, p);
        }
    }//leGrafo()

    void printGrafo(int inicio)
    {
        int v, p;
        for(int i=inicio; i<this->v+inicio; i++)
        {
            std::cout << i << " -> ";
            std::list<std::pair<int, int>>::iterator it;
            for(it=adj->begin(); it!=adj->end(); it++)
            {
                v = it->first;
                p = it->second;
                //cout <<
            }
        }
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}