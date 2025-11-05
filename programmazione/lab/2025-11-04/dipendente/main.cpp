#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Classe Dipendente
class Dipendente {
private:
    string id;
    string nome;
    string cognome;
    float stipendio;

public:
    // Costruttore
    Dipendente(string id, string nome, string cognome, float stipendio)
        : id(id), nome(nome), cognome(cognome), stipendio(stipendio) {}

    // Getter
    string getId() const { return id; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    float getStipendio() const { return stipendio; }

    // Setter
    void setNome(const string& n) { nome = n; }
    void setCognome(const string& c) { cognome = c; }
    void setStipendio(float s) { 
        if (s >= 0) stipendio = s; 
    }

    // Metodo per stampare i dati del dipendente
    void stampa() const {
        cout << "ID: " << id 
             << " | Nome: " << nome 
             << " | Cognome: " << cognome 
             << " | Stipendio: €" << fixed << setprecision(2) << stipendio << endl;
    }

    // Overload operatore <<
    friend ostream& operator<<(ostream& os, const Dipendente& d) {
        os << "ID: " << d.id 
           << " | Nome: " << d.nome 
           << " | Cognome: " << d.cognome 
           << " | Stipendio: €" << fixed << setprecision(2) << d.stipendio;
        return os;
    }
};

// Classe GestoreDipendenti
class GestoreDipendenti {
private:
    vector<Dipendente> dipendenti;

public:
    // Aggiunge un dipendente se l'id non esiste già
    bool aggiungiDipendente(Dipendente d) {
        if (esisteDipendente(d.getId())) {
            return false;
        }
        dipendenti.push_back(d);
        return true;
    }

    // Verifica se esiste un dipendente con un determinato id
    bool esisteDipendente(string id) const {
        for (const auto& dip : dipendenti) {
            if (dip.getId() == id) {
                return true;
            }
        }
        return false;
    }

    // Rimuove un dipendente dato l'id
    void rimuoviDipendente(string id) {
        for (auto it = dipendenti.begin(); it != dipendenti.end(); ++it) {
            if (it->getId() == id) {
                dipendenti.erase(it);
                return;
            }
        }
    }

    // Stampa tutti i dipendenti
    void stampa() const {
        if (dipendenti.empty()) {
            cout << "Nessun dipendente presente." << endl;
            return;
        }
        
        cout << "\n=== ELENCO DIPENDENTI ===" << endl;
        for (const auto& dip : dipendenti) {
            dip.stampa();
        }
        cout << "=========================" << endl;
    }

    // Calcola il costo totale degli stipendi
    float calcolaCostoDipendenti() const {
        float totale = 0.0f;
        for (const auto& dip : dipendenti) {
            totale += dip.getStipendio();
        }
        return totale;
    }

    // Metodo aggiuntivo: restituisce il numero di dipendenti
    int getNumeroDipendenti() const {
        return dipendenti.size();
    }

    // Overload operatore <<
    friend ostream& operator<<(ostream& os, const GestoreDipendenti& g) {
        if (g.dipendenti.empty()) {
            os << "Nessun dipendente presente.";
            return os;
        }
        
        os << "\n=== ELENCO DIPENDENTI ===" << endl;
        for (const auto& dip : g.dipendenti) {
            os << dip << endl;
        }
        os << "=========================";
        return os;
    }
};

// Funzione main di esempio
int main() {
    GestoreDipendenti gestore;

    // Creazione dipendenti
    Dipendente d1("001", "Mario", "Rossi", 1500.50);
    Dipendente d2("002", "Laura", "Bianchi", 1800.00);
    Dipendente d3("003", "Giuseppe", "Verdi", 2000.75);
    Dipendente d4("001", "Paolo", "Neri", 1600.00); // ID duplicato

    // Aggiungi dipendenti
    cout << "=== AGGIUNTA DIPENDENTI ===" << endl;
    cout << "Aggiunta d1: " << (gestore.aggiungiDipendente(d1) ? "OK" : "FALLITA") << endl;
    cout << "Aggiunta d2: " << (gestore.aggiungiDipendente(d2) ? "OK" : "FALLITA") << endl;
    cout << "Aggiunta d3: " << (gestore.aggiungiDipendente(d3) ? "OK" : "FALLITA") << endl;
    cout << "Aggiunta d4: " << (gestore.aggiungiDipendente(d4) ? "OK" : "FALLITA (ID duplicato)") << endl;

    // Stampa dipendenti
    gestore.stampa();

    // Verifica esistenza
    cout << "\n=== VERIFICA ESISTENZA ===" << endl;
    cout << "Esiste dipendente 002? " << (gestore.esisteDipendente("002") ? "SI" : "NO") << endl;
    cout << "Esiste dipendente 999? " << (gestore.esisteDipendente("999") ? "SI" : "NO") << endl;

    // Calcola costo totale
    cout << "\n=== COSTO DIPENDENTI ===" << endl;
    cout << "Costo totale: €" << fixed << setprecision(2) 
         << gestore.calcolaCostoDipendenti() << endl;
    cout << "Numero dipendenti: " << gestore.getNumeroDipendenti() << endl;

    // Rimuovi dipendente
    cout << "\n=== RIMOZIONE DIPENDENTE ===" << endl;
    cout << "Rimozione dipendente 002..." << endl;
    gestore.rimuoviDipendente("002");

    // Stampa usando operatore <<
    cout << gestore << endl;

    // Calcola nuovo costo
    cout << "\nCosto totale dopo rimozione: €" << fixed << setprecision(2) 
         << gestore.calcolaCostoDipendenti() << endl;

    return 0;
}