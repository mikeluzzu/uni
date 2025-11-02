// Esercizio 5. Calcolo del perimetro di un cerchio
// Chiedi all'utente di insierire il raggio di un cerchio
//Calcola e stampa la circonferenza usando 
// π=3.14159

#include <iostream>
using namespace std;

float circonferenza(){
    float r;
    float p = 3.14159;
    cout << "Inserisci il raggio: \n";
    cin >> r;
    float circonferenza = 2 * p * r;
    return circonferenza; 
}

int main(){
    circonferenza();
    return 0;
}