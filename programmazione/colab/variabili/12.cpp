//Leggere una stringa dall'utente e convertirla tutta in maiuscolo, quindi stamparla.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string testo = "ciao";
    for (char& i : testo){
        i = toupper(i);
    }
    cout << testo << endl;
    return 0;
}