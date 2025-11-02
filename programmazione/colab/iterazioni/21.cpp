//Stampare il conto alla rovescia da 100 a 1, ma non stampare i numeri che sono multipli di 3.


#include <iostream>
using namespace std;

int main(){
    for(int i = 100; i > 0; i--){
        if (i % 3 == 0){
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
return 0;
}