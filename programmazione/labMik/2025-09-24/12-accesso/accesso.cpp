// hiedi all'utente di inserire un PIN di 4 cifre. Se il PIN è corretto (es. 1234), chiedi un
// secondo codice segreto (es. 4321). Se entrambi sono corretti, stampa "Accesso consentito".
// Altrimenti, stampa "Accesso negato"

#include <iostream>

using namespace std;

void controllo(){
    int pin = 1234;
    int codiceSegreto = 4321;
    int pinUtente;
    int codiceUtente;

    cout << "Inserisci il pin\n";
    cin >> pinUtente;


    if (pinUtente == pin){
        cout << "Inserisci il codice segreto:\n";
        cin >> codiceUtente;
        if (codiceUtente == codiceSegreto){
            cout << "Accesso consentito\n";
        }else{
            cout << "Accesso negato\n";
        }
    }else{
        cout << "Accesso negato\n";
    }
}

int main(){
    controllo();
    return 0;
}