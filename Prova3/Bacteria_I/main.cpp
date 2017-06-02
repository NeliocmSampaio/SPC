#include <iostream>

using namespace std;

int main() {
    string dna, cG;

    while(cin >> cG >> dna)
    {

        //cout << cG.find(dna) << endl;
        if(cG.find(dna) < cG.size()-dna.size()+1)
        {
            cout << "Resistente" << endl;
        }else
        {
            cout << "Nao resistente" << endl;
        }//else
    }//while

    return 0;
}