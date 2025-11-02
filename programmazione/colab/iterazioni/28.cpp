//Stampare le cifre di un numero intero fornito dall'utente una alla volta.

#include <iostream>
using namespace std;

int main(){
    cout << "Inserisci un numero\n";

    int n;
    cin >> n;
    string s = to_string(n);

    for (char i : s){
        cout << i;
    }

}