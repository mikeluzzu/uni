#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H
#include <string>
using namespace std;
class Pubblicazione{

    protected:
            unsigned int id;
            string titolo;
            string nomeAutore;
    public:
            // se passo titolo come riferimento metto const cosi evito di modificarlo
            Pubblicazione(unsigned id,const string & titolo,const string & nomeAutore):id(id),titolo(titolo),nomeAutore(nomeAutore){}

            void setId(unsigned int id);
            void setTitolo(const string & titolo);
            void setNomeAutore(const string & nomeAutore);

            void mostraDettagli();
            

            
};

#endif 