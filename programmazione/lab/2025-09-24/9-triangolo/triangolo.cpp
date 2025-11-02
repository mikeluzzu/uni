//Esercizio 9: Triangolo scaleno, isoscele o equilatero
//Chiedi all'utente di inserire la lunghezza dei tre lati di un triangolo. Stampa se il triangolo è
//equilatero, isoscele o scaleno.

#include<iostream>
using namespace std;

void triangolo(){
    int n1, n2, n3;
    cout << "Scegli la lunghezza dei 3 lati:\n"; 
    cin >> n1 >> n2 >> n3;
    if (n1 == n2 == n3){
        cout << "Equilatero\n";
    }else if (n1 != n2 != n3){
        cout << "Scaleno\n";
    }else{
        cout << "Isoscele\n";
    }
}

int main(){
    triangolo();
    return 0;
}