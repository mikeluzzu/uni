// si scriva un programma che dato un numero binario in input lo trasformi
// decimale. Esempio dato il numero 1001101 il programma dovrà stampare 77.

#include<iostream>
#include<string>
using namespace std;


int main(){
    cout << "Inserisci un numero binario: \n";
    string binario;
    cin >> binario;
    int risultato = 0;
    for (int i = binario.length()-1, base = 1; i >= 0; i--, base*=2){
        if(binario[i] == '1'){
            risultato += base;
        }else if (binario[i] == '0'){
            continue;
        }
    }
    
    cout << "Il numero in decimale è : " << risultato << endl; 
}