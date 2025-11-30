#ifndef STUDENTE_DINAMICO_H
#define STUDENTE_DINAMICO_H
#include "Data.h"
#include <iostream>
using namespace std;

class StudenteDinamico {
private:
    int matricola;
    Data dataNascita;
    int* voti; // Array dinamico di 25 voti
    
public:
    // Costruttore base
    StudenteDinamico() : matricola(0), voti(new int[25]) {
        for(int i = 0; i < 25; i++) {
            voti[i] = 0; // Inizializza tutti a 0 (esami non sostenuti)
        }
    }
    // regola dei 3: costruttore per copia, operatore di assegnamento e operatore di uguaglianza
    // Costruttore di copia
    StudenteDinamico(const StudenteDinamico& altro) : 
        matricola(altro.matricola),
        dataNascita(altro.dataNascita),
        voti(new int[25]) {
        for(int i = 0; i < 25; i++) {
            voti[i] = altro.voti[i];
        }
    }
    
    // Distruttore
    ~StudenteDinamico() {
        delete[] voti;
    }
    
    // Operatore di assegnamento
    StudenteDinamico& operator=(const StudenteDinamico& altro) {
        if(this != &altro) {
            matricola = altro.matricola;
            dataNascita = altro.dataNascita;
            for(int i = 0; i < 25; i++) {
                voti[i] = altro.voti[i];
            }
        }
        return *this;
    }
    
    // Set e get matricola
    void setMatricola(int m) { matricola = m; }
    int getMatricola() const { return matricola; }
    
    // Set e get per il voto di un dato esame
    void setVoto(int numeroEsame, int voto) {
        if(numeroEsame >= 0 && numeroEsame < 25) {
            if((voto >= 0 && voto <= 30)) {
                voti[numeroEsame] = voto;
            }
        }
    }
    
    int getVoto(int numeroEsame) const {
        if(numeroEsame >= 0 && numeroEsame < 25) {
            return voti[numeroEsame];
        }
        return -1;
    }
    
    // Set e get data nascita
    void setDataNascita(const Data& d) { dataNascita = d; }
    // prendo direttamente il riferimento alla data, const perchè non posso modificarlo perchè è un get
    // se volessi modificarlo devo passare dai get fatti appositamente
    const Data& getDataNascita() const { return dataNascita; }
    
    // getMedia - calcola la media dei voti superati
    float getMedia() const {
        float somma = 0;
        int count = 0;
        for(int i = 0; i < 25; i++) {
            if(voti[i] >= 18 && voti[i] <= 30) {
                somma += voti[i];
                count++;
            }
        }
        if(count == 0) return 0.0f;
        return somma / count;
    }
    
    // getVotoMax - restituisce il voto più alto
    int getVotoMax() const {
        int max = 0;
        for(int i = 0; i < 25; i++) {
            if(voti[i] > max) {
                max = voti[i];
            }
        }
        return max;
    }
    
    // getNumEsamiAllaLaurea - restituisce gli esami mancanti
    int getNumEsamiAllaLaurea() const {
        int esamiSuperati = 0;
        for(int i = 0; i < 25; i++) {
            if(voti[i] >= 18 && voti[i] <= 30) {
                esamiSuperati++;
            }
        }
        return 25 - esamiSuperati;
    }
    
    // studentePiuGiovaneDi - confronta le età
    bool studentePiuGiovaneDi(const StudenteDinamico& S) const {
        // Uno studente è più giovane se è nato dopo (data più recente)
        return dataNascita.maggioreDi(S.dataNascita);
    }
    
    // Operatore di input
    friend istream& operator>>(istream& in, StudenteDinamico& s) {
        cout << "Inserisci matricola: ";
        in >> s.matricola;
        cout << "Inserisci data di nascita:\n";
        in >> s.dataNascita;
        cout << "Inserisci i 25 voti (0 per non sostenuto, 1-17 non superato, 18-30 superato):\n";
        for(int i = 0; i < 25; i++) {
            cout << "Esame " << (i+1) << ": ";
            in >> s.voti[i];
        }
        return in;
    }
    
    // Operatore di output
    friend ostream& operator<<(ostream& out, const StudenteDinamico& s) {
        out << "Matricola: " << s.matricola << endl;
        out << "Data di nascita: " << s.dataNascita << endl;
        out << "Voti: ";
        for(int i = 0; i < 25; i++) {
            out << s.voti[i] << " ";
        }
        out << endl;
        out << "Media: " << s.getMedia() << endl;
        out << "Esami mancanti: " << s.getNumEsamiAllaLaurea() << endl;
        return out;
    }
};

#endif
