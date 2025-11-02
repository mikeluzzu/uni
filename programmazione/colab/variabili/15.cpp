//Leggere una frase dall'utente, quindi stampare solo le prime 5 
// lettere della frase.

#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "Inserisci una frase: \n";
    string frase;
    cin >> frase;
    if (frase.length() >= 5){
        for (char i = 0; i < 5; i++){
            cout << frase[i];
        }
    cout << endl;
    }
    return 0;
    }
    
