// //Esercizio 10: Anno bisestile
// Chiedi all'utente di inserire un anno. Controlla se è un anno
//  bisestile. Un anno è bisestile se
// è divisibile per 4, tranne i secoli (anni divisibili per 100) 
// che non sono anche divisibili per 400.

#include <iostream>
using namespace std;

void anno(){
    int anno;
    cout << "Inserisci un anno\n";
    cin >> anno;
    
    if (anno % 4 || (anno % 100 && anno % 400)){
        cout << "Bisestile\n";
    }else{
        cout << "Non bisestile\n";
    }
}

int main(){
    anno();
    return 0;
}