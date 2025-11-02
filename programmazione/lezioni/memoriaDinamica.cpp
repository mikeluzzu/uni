#include <iostream>
using namespace std;

// La funzione deve ricevere il puntatore e la dimensione
bool controllo(int* pArray, int lung) {
    // Verifica se l'array ha lunghezza pari
    if (lung % 2 != 0) {
        cout << "L'array deve avere lunghezza pari" << endl;
        return false;
    }
    
    int meta = lung / 2;
    
    // Confronta prima metà con seconda metà
    for(int i = 0; i < meta; i++) {
        if (pArray[i] != pArray[meta + i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int* pArray = nullptr;
    int size = 10;
    
    pArray = new int[size];
    
    cout << "Inserisci 10 numeri:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "Numero " << (i+1) << ": ";
        cin >> pArray[i];
    }
    
    cout << "\nArray inserito: ";
    for(int i = 0; i < size; i++) {
        cout << pArray[i] << " ";
    }
    cout << endl;
    
    // Chiama la funzione di controllo
    if (controllo(pArray, size)) {
        cout << "Le due meta sono uguali" << endl;
    } else {
        cout << "Le due meta sono diverse" << endl;
    }
    
    delete[] pArray;
    
    return 0;
}