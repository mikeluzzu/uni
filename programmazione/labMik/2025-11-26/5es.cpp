// dati due elenchi ordinati di numeri interi, uniscili in una singola lista ordinata. 
// Le due liste di partenza possono essere, ad esempio, {1,3,5,7} e {8,2,4,6}. La lista finale
// deve essere ordinata senza utilizzare sort() sulla lista unita.

#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> lista1 = {1,3,5,7};
    list<int> lista2 = {8,2,4,6};

    cout << "Liste originali: " << endl;
    cout << "Lista 1: ";
    for (auto valore : lista1){
        cout << valore << " ";
    }
    cout << "Lista 2: ";
    for (auto valore : lista2){
        cout << valore << " ";
    }
    cout << endl;

    lista1.sort();
    lista2.sort();

    lista1.merge(lista2);

    cout << "Lista finale unita: " << endl;

    for (auto valore : lista1){
        cout << valore << " ";
    }
    cout << endl;

}