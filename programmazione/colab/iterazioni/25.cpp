// Stampare le potenze di 2 fino a 1024

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int potenza;
    int i = 1;
    while (potenza <= 1024){
        if (potenza > 1024){
            break;
        }
        potenza = pow(2,i);
        i++;
        cout << potenza << " ";
    }
    cout << endl;
    return 0;
}