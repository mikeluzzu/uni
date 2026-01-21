#ifndef CODADALPARRUCCHIERE_H
#define CODADALPARRUCCHIERE_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;

class CodaDalParrucchiere{
    protected:
        // mappa: parrucchiere -> coda dei suoi clienti
        map<string, queue<string>> code;

    public:
        CodaDalParrucchiere(const vector<string>& listaParrucchieri){
            for (const string& p : listaParrucchieri){
                code[p] = queue<string>(); // coda vuota per ogni parrucchiere
            }
        }
        // aggiungi prenotazione
        bool aggiungiPrenotazione(const string& cliente, const string& parrucchiereDesiderato){
            //verifica che il parrucchiere esiste
            if(code.find(parrucchiereDesiderato) == code.end())
                return false;

            //se il parrucchiere desiderato ha meno di 10 clienti, assegna lui
            if(code[parrucchiereDesiderato].size() < 10){
                code[parrucchiereDesiderato].push(cliente);
                return true;
            }

            // altrimenti, cerca il parrucchiere con meno clienti
            string parrucchiereMenoCarico = "";
            size_t minClienti = 11; // piu di 10

            for (auto& coppia : code){
                if(coppia.second.size() < minClienti){
                    minClienti = coppia.second.size();
                    parrucchiereMenoCarico = coppia.first;
                }
            }

            // se tutti hanno 10 o piu clienti, rifiuta la prenotazione
            inf(minClienti >= 10)
                return false;
            
            //altrimenti assegna al parruchiere meno carico
            code[parrucchiereMenoCarico].push(cliente);
            return true;
        }

        // cancellare la prenotazione
        bool cancellaPrenotazione(const string& cliente){
            // cerco l cliente in tutte le code
            for (auto& coppia : code ){
                queue<string>& coda = coppia.second;
                //crea una coda teamporanea per esplorare
                queue<string> temp;
                int posizione = 0;
                bool trovato = false;

                // cercail cliente e conta la sua posizione
                while(!coda.empty()){
                    string c = coda.front();
                    coda.pop();

                    if(c == cliente && !trovato){
                        trovato = true;
                        // se la posizione e' < 3, la prenotazione e' imminente e non puoi cancellarla
                        if(posizione < 3){
                            // ricostruisci la coda col cliente (non puoi cancellarla)
                            temp.push(c);
                        }
                        // altrimenti non aggiungere il cliente (cancellato)
                    }else{
                        temp.push(c);
                    }

                    if(!trovato){
                        posizione++;
                    }
                }
            
            // ripristina la coda
            coda = temp;
            
            if (trovato && posizione >= 3){return true;}
            if(trovato){return false;}

            }
            return false;
        }

        virtual int stimaTempoAttesa(const string& cliente) const {
            // cerca il cliente in tutte le code
            for (cost auto& coppia : code){
                queue<string> codaCopia = coppia.second; // copia per non modificare
                int posizione = 0;

                while(!codaCopia.empty()){
                    if(codaCopia.front() == cliente){
                        // trovato, il tempo e': posizione * 15 minuti
                        return posizione * 15;
                    }
                    codaCopia.pop();
                    posizione++;
                }
            }
            // cliente non trovato, tempo indefinito
            return -1;
        }
};

#endif