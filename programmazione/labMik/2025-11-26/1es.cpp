// crea una lista di numeri interi e inserissci i numeri da 1 a 10. Stampa il contenuto 
// della lista usando un ciclo for o un iteratore, rimuovi i pari dalla lista e ristampa la lista 

#include <iostream>
#include <list>
using namespace std;

bool pari(const int & v) {return (v % 2 == 0);}

int main(){
    list<int> numeri;
    int len = 10;
    for (auto i = 1; i <= len; i++){
        numeri.push_back(i);
    }
    cout << "Lista originale" << endl;

    for (auto i : numeri){
        cout << i  << " ";
    }
    cout << endl;

    numeri.remove_if(pari);

    cout << "Lista dopo rimozione dei pari" << endl;
    for (auto i : numeri){
        cout << i << " ";
    }
    cout << endl;
}
