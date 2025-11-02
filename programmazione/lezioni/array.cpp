// lezione 2 ottobre 2025 

#include <iostream>

using namespace std;

int main(){

    int a[20] = {1000, 2000, 3000};
    // cout << a;   stampa l'indirizzo di memoria del primo elemento

    int *p = nullptr; //dichiaro il puntatore (che non punta a niente)
    if (p!=nullptr){
        // controllo se il puntatore non è nullo per deferenziarlo
    }

    int x = 7; // assegno il valore alla variabile 
    p = &x; //assegno l'indirizzo di memoria di x al puntatore
    
    
    int *q = a; //prendo l'indirizzo del primo elemento dell'array
    int somma = 0;
    q++; // qui mi sposto di 1 valore nell'array (in questo caso mi sposto di 4 byte) 
    // a[i] <-> q[i] <->*(q+1);
    for (unsigned i = 0; i<=20; i++){
        somma += q[i];
    }
    cout << somma << endl;

    return 0;
}  
