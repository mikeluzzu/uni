#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct DatiAlloggi {
    vector<string> studenti;
    vector<pair<string,string>> inc;
    vector<pair<unsigned,vector<string>>> stanze;
};

unsigned getCapienza(unsigned idStanza){return (idStanza % 6) +1;}

bool checkCompatibilita(const string& studente, const vector<string>& occupanti,
                        const vector<pair<string, string>>& inc){


    for (const string& compagno : occupanti){
        for(const auto& coppia : inc) {
            if ((coppia.first == studente && coppia.second == compagno ) || 
                (coppia.first == compagno && coppia.second == studente)) {return false};
        }
    }
    return true;
}


bool esercizio4(int idxStudente, DatiAlloggi& dati){
    if (dati.studenti.size() < dati.stanze.size()){return false;}

    if (idxStudente == dati.studenti.size()){
        for (const auto& stanza : dati.stanze){
            if (stanza.second.empty()){return false;}
        }
        return true;
    }

    string studenteCorrente = dati.studenti[idxStudente];

    for (auto& stanza : dati.stanze){
        unsigned id = stanza.first;
        vector<string>& occupanti = stanza.second;
        
        //stanza piena, salta
        if occupanti.size() >= getCapienza(id){continue;}
        // compagni incompatibili, salta
        if(!checkCompatibilita(studenteCorrente, occupanti, dati.inc)){continue;}

        occupanti.push_back(studenteCorrente);

        if (risolvi(idxStudente + 1, dati)){
            return true;
        }

        occupanti.pop_back();
    }
    return false;
}

