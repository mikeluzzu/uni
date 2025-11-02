//Definire una variabile testo con il valore "Python è divertente".
// Estrarre la sottostringa "divertente" e stamparla

#include <iostream>
#include <string>
using namespace std;

int main(){
    string frase = "Python e divertente";
    string parolaDaTrovare = "divertente";
    size_t posizione = frase.find(parolaDaTrovare);
    if (posizione != string::npos){
        string estratta = frase.substr(posizione, parolaDaTrovare.length());
        cout << "sottrostringa trovata: " << estratta << endl;
    }else{
        cout << "sottostringa non trovata" << endl;
    }
    

    return 0;
}