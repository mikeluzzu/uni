// Leggere una stringa dall'utente, assegnarla alla variabile parola, e
//  stampare la lunghezza della stringa.
#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Inserisci una stringa\n";
    string utente;
    cin >> utente;
    cout << utente.length() << endl;
    return 0; 
}