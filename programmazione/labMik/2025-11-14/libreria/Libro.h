#ifndef LIBRO_H
#define LIBRO_H
#include <string>
#include "Pubblicazione.h"

class Libro : public Pubblicazione{
        
    private:
            int numeroPagine;
            

    public:
            Libro(unsigned id,const string & titolo,const string & nomeAutore, int numeroPagine) 
                : Pubblicazione(id,titolo,nomeAutore),numeroPagine(numeroPagine){}
        
        void setNumeroPagine(int numeroPagine){this->numeroPagine=numeroPagine;}
        void mostraDettagli() const {
                
        }
            
};

#endif