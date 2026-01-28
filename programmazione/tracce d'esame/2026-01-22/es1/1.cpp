// date la seguente porzione di programma rispondere alle domande corrispondenti
// motivando le risposte date:

int main() {
    int * matricola = new int[6]{2,6,1,1,9,0};
    int * tmp = new int [1];
    int& r = matricola[0];
    int * p = matricola;

    // 1. Le seguenti istruzioni sono corrette? Motivare

    for (int i = 0; i < 6; i++) tmp[i] += matricola[i];

    // 2. L'istruzione seguente e' corretta? Se si, cosa stampa?
    cout << r << endl;

    // 3. Le seguenti istruzioni sono corrette? Se si, cosa stampano?

    if (*p == r) cout << "Yes" << endl;
    else cout << "No" << endl;

    if (p == &r) cout << "Yes" << endl;
    else cout << "No" << endl;

    // 4. Scrivere sul foglio le operazioni necessarie per deallocare 
    // la memoria dinamica utilizzata

    return 0;
}