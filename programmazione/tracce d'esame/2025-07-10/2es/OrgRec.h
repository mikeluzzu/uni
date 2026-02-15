#ifndef OrganizzaRecensioni_H
#define OrganizzaRecensioni_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Ristorante {
    string nome;
    string localita;
    pair<double, double> coordinate;
    int prezzo;
    int qualita;
    int location;
    int originalita;

    Ristorante() : prezzo(0), qualita(0), location(0), originalita(0) {}
    Ristorante(string n, string l, pair<double, double> coord,
               int p, int q, int loc, int orig) 
               : nome(n), localita(l), coordinate(coord), 
               prezzo(p), qualita(q), location(loc), originalita(orig) {}

    int getVoto(const string& categoria) const {
        if (categoria == "prezzo") return prezzo;
        if (categoria == "qualita") return qualita;
        if (categoria == "location") return location;
        if (categoria == "originalita ") return originalita;
        return -1;
    }
};

class OrganizzaRecensioni {
private:
    map<pair<string,string>, Ristorante> recensioni;
public:
    void aggiungiRecensione(string nome, string localita, 
        pari<double,double> coordinate, int prezzo, int qualita, int location, int originalita){
        
        Ristorante r (nome,localita,coordinate,prezzo,qualita,location,originalita);
        auto chiave = make_pair(nome,localita);
        recensioni[chiave] = r;
    }

    int valutazione(const string& rist, const string& loc , const string& cat){
        auto chiave = make_pair(rist, loc);
        if(recensioni.find(chiave) == recensioni.end()){return -1;}
        return recensioni[chiave].getVoto(cat);
    }

    vector<Ristorante> filtraOrdina(int x, const string& filtro, const string& ordine){
        vector<Ristorante> risultato;

        for(auto& coppia : recensioni){
            Ristorante& r = coppia.second;
            if(r.getVoto(filtro) >= x) {
                risultato.push_back(r);
            }
        }
        sort(risultato.begin(), risultato.end()), [ordine] (const Ristorante& a, const Ristorante& b){
                return a.getVoto(b) > b.getVoto(b);
            }
        return risultato;
    }
};
#endif