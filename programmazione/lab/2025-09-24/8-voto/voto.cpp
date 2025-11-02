//Chiedi all'utente di inserire un voto da 0 a 100. Classifica il voto come "Insufficiente" (meno
//di 60), "Sufficiente"(da 60 a 79), "Buono" (da 80 a 89) o "Ottimo" (da 90 a 100).

#include <iostream>
using namespace std;

void voto(){
    int voto;
    cout << "Insierisci un voto da 1 a 100\n";
    cin >> voto;
    if (voto < 60){
        cout << "Insufficiente\n";
    }else if (voto >= 60 && voto <= 79) {
        cout << "Sufficiente\n";
    }else if (voto >= 80 && voto <= 89){
        cout << "Buono\n";
    }else if (voto >= 90 && voto <= 100){
        cout << "Ottimo\n";
    }
}

int main(){
    voto();
    return 0;
}