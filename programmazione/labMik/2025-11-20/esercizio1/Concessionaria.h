#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"
#include <vector>

using namespace std;


class Concessionaria {
    private:
        // lista veicoli
        vector<Veicolo*> veicoli;

    public:
         // costruttore che prende il vector di veicoli
        Concessionaria(): veicoli({}) {}

        // get dei veicoli tramite puntatore del vettore
        vector<Veicolo*> getVeicoli() const {return veicoli;}

        bool aggiungi(Veicolo* v);
        bool rimuovi(const string& targa);
};

#endif