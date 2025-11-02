// //Scrivere un programma che riceva una sequenza di dati relativi ai tassi di inquinamento registrati giorno per giorno in
// una certa località ed in un certo periodo di tempo e determini e stampi il numero dei picchi massimi dell’inquinamento.
// La sequenza è terminata da un numero negativo. I tassi di inquinamento sono interi tra 0 e 100. Un picco massimo di
// inquinamento è un massimo relativo nella sequenza, ossia un dato che è maggiore sia di quello ad esso precedente sia di
// quello ad esso seguente. Per ogni picco il programma deve visualizzare il valore del tasso di inquinamento ed il giorno in
// cui si verifica (i giorni vanno contati a partire da 1). Il programma deve altresì visualizzare il numero dei picchi rilevati
// ed il numero totale dei dati in input. Il primo e l’ultimo dato non vanno gestiti.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int seq[] = {50, 100, 20, 3, 40, 60, 10, 20, 5, 40, 20, 60, 70, 50, -1};
    int contaPicchi = 0;
    int nTotDati = 0;

    // Calcolo numero totale di dati (escludendo il -1)
    while (seq[nTotDati] >= 0) {
        nTotDati++;
    }

    vector<pair<int, int>> picchi;  // pair<tasso, giorno>

    // Analizza la sequenza dal secondo al penultimo elemento
    for (int i = 1; i < nTotDati - 1; i++) {
        if (seq[i] > seq[i - 1] && seq[i] > seq[i + 1]) {
            contaPicchi++;
            picchi.push_back({seq[i], i + 1});  // Giorni partono da 1
        }
    }

    // Stampa i picchi
    for (auto p : picchi) {
        cout << "Picco di " << p.first << " al giorno " << p.second << endl;
    }

    cout << "Numero di picchi: " << contaPicchi << endl;
    cout << "Numero totale dei dati: " << nTotDati << endl;

    return 0;
}
