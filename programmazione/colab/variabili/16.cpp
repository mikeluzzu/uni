//Leggere una parola dall'utente e stamparla al contrario.

#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "inserisci una parola" << endl;
    string parola;
    cin >> parola;
    for (int i = parola.length()-1; i>=0; i--){
        cout << parola[i];
    }
    cout << endl;
    return 0;
}