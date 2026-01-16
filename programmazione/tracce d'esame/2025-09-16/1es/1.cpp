int f (int& k) {return k+2}
int main() {
int* matricola = new int[6] {2,6,1,1,9,0};
// 1. La seguente istruzione è corretta? Se si, cosa stampa?
    // non corretta, il codice non compila
cout << *(matricola[2]) << endl;

// 2. La seguente istruzione è corretta? Se si, che cosa stampa?
    // corretta, stampa 3 1 
matricola[3] = f(matricola[2]);
cout << matricola[3] << “ “ << matricola[2] << endl;

// 3. Le seguenti istruzioni sono corrette? Motivare la risposta
    // sono scorrette
float* m = new float(6);  // sbagliato perche crea un singolo valore e non un array
for (int i=0; i < 6; i+=2) {
    m+=matricola[i] * matricola[i+1]; // sbagliato perche prova a sommare un puntatore m con valore intero
}
cout << m/=4 << endl;
// 4. Scrivere sul foglio le istruzioni per deallocare la memoria
// dinamica allocata nel programma.
delete[] matricola;
return 0;
}