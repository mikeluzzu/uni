#include "Pubblicazione.h"


    void Pubblicazione::setId(unsigned int id){
        this->id = id;
    }
    void Pubblicazione::setTitolo(const string & titolo){
        this->titolo = titolo;
    }
    void Pubblicazione::setNomeAutore(const string & nomeAutore){
        this->nomeAutore = nomeAutore; 
    }

    void Pubblicazione::mostraDettagli(){
        cout << "Id: " << id << " titolo: " << titolo << " autore: " << autore << endl; 
    }













