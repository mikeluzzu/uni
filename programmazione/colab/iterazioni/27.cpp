//Stampare tutti i numeri da 1 a 20 che sono multipli sia di 2 che di 3.

#include <iostream>
using namespace std;

int main(){

    for (int i = 1; i < 21; i++){
        if (i % 2 == 0 && i % 3 == 0){
            cout << i << " ";
        }
        continue;
    }
    cout << endl;
    return 0;
}