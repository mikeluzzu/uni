//Leggere un numero dall'utente, convertirlo in una stringa e 
// stampare il suo tipo (usando la funzione type).

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
    int numero;
    cout << "Inserisci un numero" << endl;
    cin >> numero;
    string sNum = to_string(numero);
    cout << typeof(sNum) << endl;
    return 0;
}