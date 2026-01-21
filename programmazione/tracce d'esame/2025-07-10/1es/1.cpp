int main() {
 int* matricola = new int[6] {2,6,1,1,9,0};
 // 1. La seguente istruzione è corretta? Se si, cosa stampa?

 cout << matricola + 4 << endl;
 // 2. La seguente istruzione è corretta? Se si, che cosa stampa?

 *(matricola + 3)+=2;
 cout << *(matricola)+3 << " " *(matricola+3) << endl;

 // 3. Le seguenti istruzioni sono corrette? Motivare la risposta

 int * nuova_matricola = new int[3];

 for (int i=0; i < 6; i+=2) {
nuova_matricola[i/2] = matricola[i] + matricola[i+1];
 }
// 4. Scrivere sul foglio le istruzioni per deallocare la memoria
//dinamica allocata nel programma. Scrivere “NIENTE” se non c’è bisogno di
//deallocare memoria
delete [] matricola;
delete [] nuova_matricola;

return 0;
}