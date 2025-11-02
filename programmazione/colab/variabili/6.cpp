//Leggere una stringa dall'utente e stampare la prima e l'ultima lettera.

#include <iostream>
#include <string>
using namespace std;

int main(){
    string utente;
    cout << "Inserisci una stringa" << endl;
    cin >> utente;
    cout << utente[0] << " " << utente[utente.length() -1] << endl;
    return 0;
}