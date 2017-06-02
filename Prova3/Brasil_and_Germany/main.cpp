#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    cin >> n;

    while(n!=0)
    {
        int b = floor((n/90.0)*1);
        int a = ceil((n/90.0)*7);
        printf("Brasil %d x Alemanha %d\n", b, a);

        cin >> n;
    }//while

    return 0;
}