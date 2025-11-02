// Chiedere all'utente un numero e stampare tutti i divisori di quel numero.

#include <iostream>
using namespace std;

int main(){
    cout << "inserisci un numero \n";
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            cout << i << endl;
        }
    }
    return 0;
}