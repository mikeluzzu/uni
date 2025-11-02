//Leggere una parola dall'utente e stamparla ripetuta tre volte in una sola riga.

#include <iostream>
#include <string>
using namespace std;

int main(){

    string parola = "Scimmia";
    for (int i = 1; i < 4; i++){
        cout << parola << " ";
    }
    return 0;
    
}