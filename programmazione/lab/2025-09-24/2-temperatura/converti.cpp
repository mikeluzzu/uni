// Esercizio 2. Conversione da Celsius a Fahrenheit
// Chiedi all'utente di inserire una temperatura in gradi Celsius. 
// Convertila in Fahrenheit usando la formula F = c * 9/5 + 32
//  e stampala

#include <iostream>
using namespace std;

void convert(){

    int c;
    int f;
    cout << "Inserisci una temperatura in Celsius \n";
    cin >> c;
    f = (c * 9/5) + 32;
    cout << f << endl;
}

int main(){
    convert();
    return 0;
}