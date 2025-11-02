//Stampare i numeri da 1 a 100 e contare quanti di questi numeri sono divisibili per 5.

#include <iostream>
using namespace std;

int main(){
    int cont = 0;
    for (int i = 1; i < 101; i++){
        if (i % 5 == 0){
            cont++;
        }
    }
    cout << "I numeri tra 1 e 100 divisibili per 5 sono: " << cont << endl;
    return 0;
}