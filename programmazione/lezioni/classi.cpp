/*
21 ottobre 2025
 possiamo avere piu costruttori basta che hanno diversi parametri
 costruttore per copia

 qualificatore const: puo essere applicato su oggetti che non 
 possono essere modificati, con il metodo const possiamo usare 
 solo metodi definiti costanti.

 se dichiaro e poi inizializzo un oggetto chiamo il costruttore per copia

Overloading degli operatori: 

*/

#include <iostream>
using namespace std;

int main(){
    class Cerchio{
        void operator = (const Cerchio &x){
            raggio = x.raggio;
        } // passo un oggetto per riferimento costante

    },
}

