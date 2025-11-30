// Esercizio 11: Calcolo del prezzo del biglietto del cinema
// Chiedi all'utente la sua età. Il prezzo base del biglietto è 10€. Applica uno sconto del 50%
// per i bambini (sotto i 12 anni) e del 30% per gli anziani (sopra i 65 anni). Stampa il prezzo
// finale.

#include<iostream>
using namespace std;

int biglietto(){
    int eta;
    int prezzo = 10;
    int scontoBambini = 50;
    int scontoAdulti = 30;
    int prezzoFinale;

    cout << "Inserisci la tua eta: \n";
    cin >> eta;

    if(eta < 12){
        prezzoFinale = prezzo - prezzo * 100 / 50;
    }else if(eta >= 12){
        prezzoFinale = prezzo - prezzo * 100 / 30;
    }
    return prezzoFinale;
}

int main(){
    biglietto();
    return 0;
}