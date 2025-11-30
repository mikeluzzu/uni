//crea una lista di nomi e inverti l'ordine degli elementi. La lista iniziale puo essere
// ad esempio {"Anna", "Luca", "Giovanni", "Paola"}

#include <iostream>
#include <list>
using namespace std;

int main(){
    list<string> nomi = {"Anna", "Luca", "Giovanni", "Paola"};
    cout << "Lista originale: " ;
    for (auto i : nomi){
        cout << i << " ";
    }
    cout << endl;
    nomi.reverse();

    cout << "Lista invertita: ";
    for (auto i : nomi){
        cout << i << " ";
    }
    cout << endl;
}