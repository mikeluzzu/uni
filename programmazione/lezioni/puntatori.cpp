// 2 ottobre 2025 

#include <iostream>
using namespace std; 

int main(){
    int x; // dichiaro la variabile 
    int *ptrX = &x; // dichiaro e assegno il puntatore alla variabile
    *ptrX = 8; 
    cout << ptrX << endl;
    cout << *ptrX << endl; //deferenziazione (passo dal puntatore all'elemento puntato)


    int *p = nullptr; //dichiaro il puntatore (che non punta a niente)
    if (p!=nullptr){
        // controllo se il puntatore non è nullo per deferenziarlo
    }

    int x = 7; // assegno il valore alla variabile 
    p = &x; //assegno l'indirizzo di memoria di x al puntatore
    
    int **q = &p; // puntatore ad un puntatore
    

    int x = 7;
    int &h = x; // operatore di riferimento, crea un'alias alla variabile che gli ho passato

    const int c = 2;
    const int &r = c;
    const int &rr = 2; //riferimento costante a r
    const int *p = &rr;

    const int a = 2;
    int* const q=&x; // puntatore costante all'intero
    const int *p = &x; // costante intera di un puntatores a x

    auto var = 3.2;
    
    return 0;
}
