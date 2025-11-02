//Chiedere all'utente una parola e stampare quante volte la lettera "a" compare nella parola.

#include<iostream>
#include<string>

using namespace std;

int main(){

    cout << "inserisci una parola\n";
    int cont = 0;
    string parola;
    cin >> parola;

    for (int i = 1; i < parola.length(); i++){
        if (parola[i] == "a" or parola[i] == "A"){
            cont++;
        }
    }
    cout << "nella parola ci sono: " << cont << "a" << endl;
    return 0;
}