// Esercizio 4. Scambio di valori
// Chiedi all'utente di inserire due numeri.
// Scambia i loro valori e stampali prima 
// e dopo lo scambio

#include <iostream>
using namespace std;

void scambio(){
    int a;
    int b; 
    cout << "Inserisci due numeri:\n";
    cin >> a >> b;
    cout << a << " " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

int main(){
    scambio();
    return 0;

}