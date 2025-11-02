//Creare una variabile float contenente un numero, convertirla in 
// una stringa e aggiungere il simbolo "€" alla fine. Stampare il risultato.

#include <iostream>
#include <string>
using namespace std;
int main(){
    float numero = 12;
    string valuta = to_string(numero);
    cout << valuta << "$" << endl;
    return 0;
}