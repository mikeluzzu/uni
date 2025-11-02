//Esercizio 3. Media di tre numeri
// Chiedi all'utente di inserire 3 numeri.
// Calcola e stampa la loro media

#include<iostream> 
using namespace std;

int media(){
    int n1;
    int n2;
    int n3;
    cout << "Inserisci 3 numeri: \n";
    cin >> n1 >> n2 >> n3;
    int media = (n1 + n2 + n3) / 3;
    return media;
}

int main(){
    media();
}