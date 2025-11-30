// crea una lista di numeri interi casuali tra 1 e 100 (almento 15 elementi). Stampa la lista
// poi rimuovi i numeri inferiori di 50 e ristampa. Usare un iteratore per rimuovere
// i numeri inferiori a 50, successivamente calcola e stampa la media dei valori rimanenti

#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> numeri = {1,14,45,34,98,12,37,83,42,16,19,23,70,32};

    cout << "Lista originale: " << endl; 
    for (auto i : numeri){
        cout << i << " "; 
    }

    cout << endl;

    auto i = numeri.begin();
    while (i != numeri.end()){
        if(*i < 50){  //dereferenzio l'iteratore
            i = numeri.erase(i);
        } else{
            ++i; //incrementa solo sen ha rimosso
        }
    }

    cout << "Valori rimanenti: " << endl;
    for (auto i : numeri){
        cout << i << " ";
    }
    cout << endl;
    if(!numeri.empty()){
        double somma = 0;
        for(auto valore : numeri){
            somma += valore;
        }
        double media = somma / numeri.size();
        cout << "Media dei valori rimanenti: " << media << endl;
    }else{
        cout << "Nessun elemento da calcolare." << endl;
    }


    return 0;
}