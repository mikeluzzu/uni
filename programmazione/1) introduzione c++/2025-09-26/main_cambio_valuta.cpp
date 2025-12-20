/*
Scrivi un programma in C++ che funge da convertitore di valute semplice. 
L'utente dovrà inserire un valore in Euro e scegliere la valuta di destinazione (Dollari USA, Yen Giapponesi, o Sterline Britanniche) tramite un menu numerato. 
Il programma dovrà poi visualizzare l'importo convertito sapendo che:
-> 1 Euro = 1.08 Dollari USA

-> 1 Euro = 168.22 Yen Giapponesi

-> 1 Euro = 0.86 Sterline Britanniche

*/

#include <iostream>

using namespace std;

int main() {
    // Definizione dei tassi di cambio
    const double TASSO_DOLLARI = 1.08;
    const double TASSO_YEN = 168.22;
    const double TASSO_STERLINE = 0.86;

    double euro, conversione;
    int scelta;

    cout << "Benvenuto nel convertitore di valute!" << endl;
    cout << "Inserisci l'importo in Euro: ";
    cin >> euro;

    cout << "\nScegli la valuta di destinazione:" << endl;
    cout << "1. Dollari USA " << endl;
    cout << "2. Yen Giapponesi " << endl;
    cout << "3. Sterline Britanniche " << endl;
    cout << "Inserisci il numero corrispondente: ";
    cin >> scelta;

    switch (scelta) {
        case 1:
            conversione = euro * TASSO_DOLLARI;
            cout << "\n" << euro << " Euro corrispondono a " << conversione << " Dollari USA." << endl;
            break;
        case 2:
            conversione = euro * TASSO_YEN;
            cout << "\n" << euro << " Euro corrispondono a " << conversione << " Yen Giapponesi." << endl;
            break;
        case 3:
            conversione = euro * TASSO_STERLINE;
            cout << "\n" << euro << " Euro corrispondono a " << conversione << " Sterline Britanniche." << endl;
            break;
        default:
            cout << "\nErrore: Scelta non valida. Riprova con 1, 2 o 3." << endl;
            break;
    }

    return 0;
}