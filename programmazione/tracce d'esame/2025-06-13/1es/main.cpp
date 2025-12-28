void f (int* a) { 
    int b = (*a+3); // dereferenzio il puntatore a e aggiungo 3
    int c = *(a+3); // sposto il puntatore di 3 posizioni e poi dereferenzio
    cout << b << " " << c << endl; 
} 
 
int main() {                           4
    int* matricola = new int[6] {2,6,1,1,9,0}; 
 
    // 1. La seguente istruzione è corretta? Se si, che cosa stampa? 
    f(matricola); // stampa 5 1
 
    // 2. La seguente istruzione è corretta? Se si, che cosa stampa? 
    f(matricola+3); // corretta, e stampa 4 e poi un valore indefinito perche esce dall'array
     
    // 3. Le seguenti istruzioni sono corrette? Motivare la risposta 
    while (!matricola.empty()) matricola.pop_back();  
    // matricola e' un puntatore non un vector, quindi non ha i metodi empty e pop_back
    // il codice quindi non compila
 
// 4. Scrivere sul foglio le istruzioni per deallocare la memoria dinamica allocata 
//nel programma. Scrivere “NIENTE” se non c’è bisogno di deallocare memoria 
    
    delete[] matricola;
    return 0; 
 
}


