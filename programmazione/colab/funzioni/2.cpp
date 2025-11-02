// creare una funzione quadrato(x) che prende un numero come 
// argomento e restituuisce il suo quadrato. Testare con un numero pos e neg

#include <iostream>
using namespace std;

int quadrato(int x){
    int risultato = x * x;
    return risultato;
}

int main(){
    int x = 3;
    cout << quadrato(x); // per avere a schermo il risultato di una funzione devo farne il cout
    cout << endl;
}