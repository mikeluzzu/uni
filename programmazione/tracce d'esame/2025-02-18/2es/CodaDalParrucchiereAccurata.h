#include "CodaDalParrucchiere.h"
#ifndef CODADALPARRUCCHIEREACCURATA_H
#define CODADALPARRUCCHIEREACCURATA_H

class CodaDalParrucchiereAccurata : public CodaDalParrucchiere {
    private:
        // mappa: parruchiere -> minuti per cliente
        map<string, unsigned> tempiMedi;

    public:
    // Costruttore: riceve mappa con tempi medi
    CodaDalParrucchiereAccurata(const map<string, unsigned>& tempiPerParrucchiere) 
        : CodaDalParrucchiere(estraiNomiParrucchieri(tempiPerParrucchiere)),
          tempiMedi(tempiPerParrucchiere) {}

    // stima tempo di attesa considerando la velocita dei parrucchieri
    int stimaTempoAttesa(const string& cliente) const override{
        // cerca il cliente in tutte le code
        for (const auto& coppia : code){
            queue<string> codaCopia = coppia.second;
            int posizione = 0;

            while(!codaCopia.empty()){
                if(codaCopia.front() == cliente){
                    // trovato, usa il tempo specifico del parrucchiere 
                    string parrucchiere = coppia.first;
                    unsigned minutiPerCliente = tempiMedi.at(parrucchiere);
                    return posizione * minutiPerCliente;
                }
                codaCopia.pop();
                posizione++;
            }
        }
        return -1; // cliente non trovato
    }
    private:
        // funzione helper per eestrarre i nomi dai parrucchieri della mappa 
        static vector<string> estraiNomiParrucchieri(const map<string,unsigned>& tempi){
            vector<string> nomi;
            for (const auto& coppia : tempi){
                nomi.push_back(coppia.first);
            }
            return nomi;
        }
};

#endif