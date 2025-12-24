// considerare ogni esercizio separatamente 
#include <iostream>
using namespace std;

//void f(int& a) {if (a%2==0) a++; else a-=2;}
//int &g(int& a) {int b=a; return b;}

int main() {

int* matricola = new int[6]{9,8,7,6,5,4};
// 1. Le istruzioni seguenti sono corrette? Se si, cosa viene stampato?
//f(g(matricola[2]));
//cout << matricola[2] << endl;
    // non sono corrette


// 2. Le istruzioni seguenti sono corrette? Se si, cosa viene stampato?
int* p = matricola + 4;  // p punta a matricola[4]
int* q = matricola + 3;  // q punta a matricola[3]
p = q;                   // p ora punta a matricola[3] (come q)
q = p;                   // q punta ancora a matricola[3] (nulla è cambiato)
*p = 0;                  // matricola[3] = 0
*q = 9;                  // matricola[3] = 9 (sovrascrive il valore 0)
cout << *(matricola+3) << " " << *(matricola+4) << endl;

// 3. La seguente istruzione è corretta? Se si, cosa viene stampato?
//cout << matricola[matricola+2] << endl; // non è corretta perche non prende l'intero con * 

// 4. Selezionare TUTTE le operazioni necessarie per deallocare la memoria allocata nel programma
// a. delete[] matricola; // questa
// b. delete p;
// c. for (int i=0; i < 6; i++) {delete matricola[i];}
// d. delete matricola;
// e. delete q;

return 0;
}