#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// PASSO 1: Definire la struttura per rappresentare un ristorante
struct Ristorante {
    string nome;
    string localita;
    pair<double, double> coordinate; // latitudine, longitudine
    
    // Voti per le 4 categorie (da 1 a 5)
    int prezzo;
    int qualita;
    int location;
    int originalita;
    
    // Costruttore per inizializzare facilmente un ristorante
    Ristorante(string n, string l, pair<double, double> coord,
               int p, int q, int loc, int orig)
        : nome(n), localita(l), coordinate(coord),
          prezzo(p), qualita(q), location(loc), originalita(orig) {}
    
    // Costruttore di default
    Ristorante() : prezzo(0), qualita(0), location(0), originalita(0) {}
};

// PASSO 2: Classe principale per organizzare le recensioni
class OrganizzaRecensioni {
private:
    // Mappa che associa la chiave univoca (nome+località) al ristorante
    // La chiave è una stringa formata da "nome|località"
    map<string, Ristorante> recensioni;
    
    // Funzione helper per creare la chiave univoca
    string creaChiave(const string& nome, const string& localita) const {
        return nome + "|" + localita;
    }
    
    // Funzione helper per ottenere il voto di una categoria
    int getVotoCategoria(const Ristorante& r, const string& categoria) const {
        if (categoria == "prezzo") return r.prezzo;
        if (categoria == "qualita") return r.qualita;
        if (categoria == "location") return r.location;
        if (categoria == "originalita") return r.originalita;
        return -1; // Categoria non valida
    }
    
public:
    // FUNZIONALITÀ 1: Aggiungere o aggiornare una recensione
    void aggiungiRecensione(const string& nome, const string& localita,
                           pair<double, double> coordinate,
                           int prezzo, int qualita, int location, int originalita) {
        // Crea la chiave univoca
        string chiave = creaChiave(nome, localita);
        
        // Crea il ristorante
        Ristorante r(nome, localita, coordinate, prezzo, qualita, location, originalita);
        
        // Inserisce o sovrascrive nella mappa
        // Se la chiave esiste già, il valore viene sovrascritto
        recensioni[chiave] = r;
        
        cout << "Recensione aggiunta/aggiornata per: " << nome 
             << " - " << localita << endl;
    }
    
    // FUNZIONALITÀ 2: Ottenere la valutazione di una categoria specifica
    int ottieniValutazione(const string& nome, const string& localita,
                          const string& categoria) const {
        string chiave = creaChiave(nome, localita);
        
        // Verifica se il ristorante esiste
        auto it = recensioni.find(chiave);
        if (it == recensioni.end()) {
            cout << "Ristorante non trovato!" << endl;
            return -1;
        }
        
        // Restituisce il voto della categoria richiesta
        return getVotoCategoria(it->second, categoria);
    }
    
    // FUNZIONALITÀ 3: Filtrare e ordinare ristoranti
    vector<Ristorante> filtraEOrdina(int soglia, const string& categoriaFiltro,
                                     const string& categoriaOrdine) const {
        vector<Ristorante> risultati;
        
        // FASE 1: Filtraggio
        // Seleziona solo i ristoranti con punteggio >= soglia nella categoriaFiltro
        for (const auto& coppia : recensioni) {
            const Ristorante& r = coppia.second;
            int voto = getVotoCategoria(r, categoriaFiltro);
            
            if (voto >= soglia) {
                risultati.push_back(r);
            }
        }
        
        // FASE 2: Ordinamento decrescente per categoriaOrdine
        sort(risultati.begin(), risultati.end(),
             [this, &categoriaOrdine](const Ristorante& a, const Ristorante& b) {
                 int votoA = getVotoCategoria(a, categoriaOrdine);
                 int votoB = getVotoCategoria(b, categoriaOrdine);
                 return votoA > votoB; // Ordine decrescente
             });
        
        return risultati;
    }
    
    // Funzione di utilità per stampare i risultati
    void stampaRistoranti(const vector<Ristorante>& ristoranti,
                         const string& categoria) const {
        cout << "\n=== Risultati ===" << endl;
        for (const auto& r : ristoranti) {
            int voto = getVotoCategoria(r, categoria);
            cout << r.nome << " (" << r.localita << ") - "
                 << categoria << ": " << voto << "/5" << endl;
        }
        cout << "Totale: " << ristoranti.size() << " ristoranti\n" << endl;
    }
};

