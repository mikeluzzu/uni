#include <iostream>
using namespace std;

int main(){
    unsigned int n ;
    cout << "Inserisci un numero intero positivo\n";
    cin >> n;
    unsigned int x = 1;
    unsigned int somma = 0;

    for (unsigned x = 1;somma < n; ++x){
        somma += x;
    }

    //implementazione while
    while (somma < n){
        somma += x;
        ++x;
    }
    if (somma == n){
        cout << "SI" << endl;
    }else{
        cout << "NO" << endl;
    }
}
