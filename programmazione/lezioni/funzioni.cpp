// 2 ottobre 2025

#include <iostream>
using namespace std;


// con il riferimento dico alla funzione scambia di riferirsi alle variabili nel main
void scambia(int &x , int &y){   // parametri formali, passati per riferimento
    int temp = x;
    x = y;
    y = temp;
    cout << x << " " << y << endl;  
}

//prototipo della funzione, dichiaro la funzione e gli dico al compilatore che esiste 
// una funzione specifica che passa tipi di parametri specifici
void stampaRettangolo(int, int); 

/*
void stampaRettangolo(int a, int b){
    for (int i=0; i<a; i++){
        for (int j =0; i <b; j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/

// i valori passati alle funzioni devono coincidere
void scambiaPuntatori(int*& x, int* &y){
    int * temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 2;
    int y = 3;
    scambia(x,y);    // parametri attuali
    stampaRettangolo(2,3);
}

//posso passare dei puntatori

//l'ordine in cui chiamo le funzioni è importante. 

//passare per valore e per riferimento c'è una grande differenza.

//se passo per valore devo copiare il valore e utilizzo piu memoria  
// se passo per riferimento è più efficiente perchè ti riferisci
// direttamente a quel valore
