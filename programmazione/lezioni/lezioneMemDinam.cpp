#include <iostream>
using namespace std; 

int ciao(){

    int *p = 0, *q = 0;
    int x = 0;
    q = &x;
    p = new int; // creo un intero nell'heap
    *p = 5; // deferenzio e passo 5
    x = *p; // *p punta a 5 e lo passo ad x
    *p = *q; // passo il valore di q a p
    q = p; 
    delete q;
    p = &x;
 }

 void raddoppia(int &d, int *A){
    int *temp = new int 
 }