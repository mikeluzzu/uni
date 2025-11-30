//Esercizio 6. Divisione con resto
//Chiedi all'utente di inserire due numeri interi. 
//Stampa il quoziente e il resto della divisione dei numeri

#include <iostream>
using namespace std;

void resto(){
        int n1;
        int n2;
        cout << "Inserisci due numeri interi: \n";
        cin >> n1 >> n2;
        int div = n1 / n2;
        int r = n1 % n2;
        cout << "Risultato: " << div << " " << "Resto: " << r << endl;    
    }

int main(){
    resto();
    return 0;
}