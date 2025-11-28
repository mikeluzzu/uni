// dato un elenco di numeri interi , alcuni dei quali duplicati, crea una lista e rimuovi 
// tutti i duplicati in modo che ogni numero appaia solo una volta. 
// La lista iniziale puo essere, ad esempio, {1,2,3,2,4,1,5,3,6}

#include <iostream>
#include <list>
using namespace std;


int main(){
    list<int> numeri = {1,2,3,2,4,1,5,3,6};

    cout << "lista originale:" << endl;
    for (auto i : numeri){
        cout << i << " ";
    }
    cout << endl;

    numeri.sort();
    numeri.unique();

    cout << "lista senza duplicati: " << endl;
    for (auto i : numeri){
        cout << i << " ";
    }
    cout << endl;
}