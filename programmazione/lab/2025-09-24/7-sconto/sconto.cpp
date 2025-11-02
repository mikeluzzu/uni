// Esercizio 7. Calcolo del prezzo totale con sconto
//Chiedi all'utente di inserire il prezzo di un articolo e
//  una percentuale di sconto da applicare.
//Calcola e stampa il prezzo finale dopo lo sconto

#include <iostream>
using namespace std;

int prezzo(){
    int prezzo;
    int sconto;
    cout << "Inserisci prezzo e percentuale sconto: \n";
    cin >> prezzo >> sconto;
    int prezzoFinale = prezzo - (prezzo * sconto / 100);
    return prezzoFinale;
}

int main(){
    prezzo();
    return 0;
}