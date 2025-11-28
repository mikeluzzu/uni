/*
    abbiamo l'hash delle chiavi conservate nel bucket
    per ogni chiave andiamo a trovare un match

    ogni oggetto ha una propria funzione hash

    la funzione hash ti dice esattamente dove si trova un oggetto
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){

    unordered_map<string, int> voti;  // inizializza una mappa con una stringa e un intero  

    voti["Giuseppe"] = 20; // assegnazione del valore
    voti["Michele"] = 30; 

    int votoMichele = voti["Michele"];

    auto search = example.find("Michele");
    if (search!=voti.end())
        cout << voti["Michele"] << endl;
    else
        cout << "non esiste" << endl;

    return 0;
}