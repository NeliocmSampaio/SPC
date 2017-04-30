#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main() {
    std::list<std::pair<int,int>> lista;
    lista.push_back(std::make_pair(1,2));
    return 0;
}