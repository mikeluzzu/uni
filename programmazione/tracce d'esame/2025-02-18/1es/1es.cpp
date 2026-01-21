int main() { 
    int* matricola = new int[6] {2,6,1,1,9,0}; 
 
    // 1. La seguente istruzione è corretta? Motivare la risposta 
    if (matricola.size() > 4) { 
        cout << "OK" << endl; 
    } 
    // e' corretta e stampa "ok" perche la size dell'array e' 6, che e' maggiore di 4
    // Fine blocco codice relativo a domanda 1 
 
    // 2. La seguente istruzione è corretta? Se si, cosa stampa? 
    int * p = new int[3]; 
    for (int i = 0; i < 3; i++) { 
        p[i] = matricola[i*2]; 
        cout << p[i]; 
    } 
    cout << endl; 
    // stampa 219

    // Fine blocco codice relativo a domanda 2 
 
    // 3. Perché la seguente coppia di istruzioni non è corretta? 
    *(matricola + 2) = 6; 
    matricola[matricola[2]] = 1; // questo assegna 1 a matricola[6], che non esiste perche l'array va da 0 a 5
    // Fine blocco di codice relativo a domanda 3 
 
    // 4. Selezionare TUTTE le istruzioni necessarie per deallocare la memoria allocata  
    // nel programma 
    //  a. delete matricola; 
    //  b. delete p; 
    //  c. delete[] matricola;  // questa
    //  d. delete[] p; // questa 
    //  e. for (int i=0; i < 6; i++) {delete matricola[i];} 
    //  f. for (int i=0; i < 3; i++) {delete p[i];} 
     
    return 0; 
 

}