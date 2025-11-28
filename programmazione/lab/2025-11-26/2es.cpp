// dato un elenco di nomi, crea una lista di stringhe. Aggiungi un nome all'inizio, uno alla fine
//  e rimuovi un nome specifico. Successivamente ordina la lista alfabeticamente e stampa il risultato

#include<iostream>
#include <list>
using namespace std;

bool match(const string & n) {return n == "Michele";}
int main(){
    list<string> nomi = {"Angela", "Michele", "Letizia"};

    nomi.push_front("Luigi");
    nomi.push_back("Francesco");

    nomi.remove_if(match);

    for (auto i : nomi){
        cout << i << " "; 
    }
    cout << endl;
}