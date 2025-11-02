//Definire una variabile frase con il valore "I linguaggi di 
// programmazione sono utili". Sostituire la parola "utili" con 
// "potenti" e stampare il risultato.

#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase = "I linguaggi di programmazione sono utili";
    frase.replace(35,5,"potenti");
    cout << frase << endl;
    return 0;
}