#ifndef OrganizzaRecensioni_H
#define OrganizzaRecensioni_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Ristorante {
    string nome;
    string localita;
    pair<double, double> coordinate; // latitudine, longitudine

    int prezzo;
    int qualita;
    int location;
    int originalita;
    Ristorante(string n, string l, pair<double, double> coord,
               int p, int q, int loc, int orig) 
        : nome(n), localita(l), coordinate(coord), prezzo(p), qualita(q), location(loc), originalita(orig) {}

};

class OrganizzaRecensioni {
private:
    map<string, Ristorante> recensioni;
    
    string creaChiave(const string& nome, const string& localita) const {
        return nome + "|" + localita;
    }
    int getVotoCategoria(const Ristorante& r, const string& categoria) const {
        if (categoria == "prezzo") return r.prezzo;
        if (categoria == "qualita") return r.qualita;
        if (categoria == "location") return r.location;
        if (categoria == "originalita") return r.originalita;
        return -1; // Categoria non valida
    }
    
public:
    // FUNZIONALITÀ 1: Aggiungere o aggiornare una recensione
    void aggiungiRecensione(const string& nome, const string& localita, pair<double, double> coordinate,
                           int prezzo, int qualita, int location, int originalita) {

        string chiave = creaChiave(nome, localita);
        
        Ristorante r(nome, localita, coordinate, prezzo, qualita, location, originalita);
        
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
        return getVotoCategoria(it->second, categoria);
    }
    
    vector<Ristorante> filtraEOrdina(int soglia, const string& categoriaFiltro,
                                     const string& categoriaOrdine) const {
        vector<Ristorante> risultati;
        
        for (const auto& coppia : recensioni) {
            const Ristorante& r = coppia.second;
            int voto = getVotoCategoria(r, categoriaFiltro);
            
            if (voto >= soglia) {
                risultati.push_back(r);
            }
        }

        sort(risultati.begin(), risultati.end(),
             [this, &categoriaOrdine](const Ristorante& a, const Ristorante& b) {
                 int votoA = getVotoCategoria(a, categoriaOrdine);
                 int votoB = getVotoCategoria(b, categoriaOrdine);
                 return votoA > votoB; // Ordine decrescente
             });
        
        return risultati;
    }
    
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

#endif