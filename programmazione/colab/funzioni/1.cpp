//Definire una funzione somma(a, b) che prende due numeri come argomenti 
// e restituisce la loro somma. Testare la funzione con valori diversi.

#include <iostream>
using namespace std;

// passo per valore
void somma(int n1, int n2){
    int risultato = n1 + n2;
    cout << risultato << endl;
}

//passo per riferimento
void somma2(int &n1, int &n2){
    int risultato = n1 + n2;
    cout << risultato << endl;
}

int main(){
    int n1 = 2;
    int n2 = 4;
    somma(n1,n2);
    somma2(n1,n2);
}
