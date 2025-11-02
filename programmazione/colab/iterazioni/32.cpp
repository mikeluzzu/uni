//Chiedere all'utente una parola e verificare se è palindroma. 
// Una parola è palindroma se si legge allo stesso modo
//  da sinistra a destra e da destra a sinistra.

#include <iostream>
#include <string>
using namespace std;

int main(){

    char parola[] = "michele";
    char nuova[];
    int len = sizeof(parola) / sizeof(parola[0]);
    for (int i = len; len > 0; i--){
        append(parola[i],nuova);
    }
    if (nuova == parola){
        cout << "palindroma";
    }else{
        cout << "non palindroma";
    }
}