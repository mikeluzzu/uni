// stampare la somma dei quadrati dei numeri da 1 a 10

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int somma = 0;
    for(int i = 1; i < 11; i++){
        int quadrato = pow(i,2);
        somma += quadrato;
        
    }
    cout << somma << endl;
}