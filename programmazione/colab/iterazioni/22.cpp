//Chiedere all'utente una parola e stampare solo le lettere alla posizione pari.

#include<iostream>
#include <string>
using namespace std;

int main(){
    string parola = "Michele";
    for (int i = 0; i < parola.length(); i++ ){
        if (i % 2 != 0){
            continue;
        }else{
            cout << parola[i] << endl;
        }
    }
return 0;
}