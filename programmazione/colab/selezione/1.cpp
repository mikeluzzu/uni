//Leggere un numero dall'utente e stampare "Positivo" se il
//  numero è maggiore di 0, altrimenti stampare "Non positivo".

#include <iostream>
using namespace std;

int main(){
    int numero;
    cout << "inserisci un numero" << endl;
    cin >> numero;
    if (numero > 0){
        cout << "Positivo"<< endl;
    }else if (numero < 0){
        cout << "Negativo" << endl;
    }
    return 0;
}