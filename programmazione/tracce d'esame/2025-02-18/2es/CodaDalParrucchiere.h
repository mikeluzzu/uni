/*Un  salone  di  parrucchieri,  in  cui  lavorano  un  numero  imprecisato  di  dipendenti,  ha  bisogno di un 
software per la gestione delle prenotazioni. A tal fine, si richiede di modellare ed implementare una 
classe CodaDalParrucchiere che tenga traccia delle prenotazioni assegnate a ciascun 
parrucchiere (rappresentato come stringa) ed esponga le seguenti funzionalità: 
- Un costruttore che prenda in input i parrucchieri che lavorano nel salone (tramite 
vector<string>) 
- Aggiungere una prenotazione: il metodo riceve in input un cliente (anch’esso rappresentato 
come  stringa)  e  un  parrucchiere.    Quando  un  cliente  vuole  prenotare  una  prestazione,  il 
programma  deve  cercare  di  accontentarlo  assegnandogli  il  parrucchiere  da  lui  scelto. 
Tuttavia,  nel  caso  in  cui  il  parrucchiere  desiderato  abbia  già  più  di  10  clienti  in  coda,  la 
prenotazione  sarà  assegnata  al  parrucchiere  con  meno  clienti  in  coda.  Se  non  ci  sono 
parrucchieri disponibili ad accoglierla, il sistema deve restituire false (true altrimenti).  
- Cancellare  una  prenotazione:  il  metodo  riceve  il  nome  di  un  cliente  c  e  rimuove  la  sua 
prenotazione, se e solo se essa non è imminente (consideriamo imminente la prenotazione 
di  c  se  prima  di  c  ci  sono  meno  di  3  clienti  in  fila).  Il  metodo  restituisce  true  se  la 
prenotazione è stata correttamente cancellata e false altrimenti.
- Stimare il tempo d’attesa: che restituisca, in minuti, il tempo che dobbiamo attendere prima 
di  sederci  sulla  poltrona,  considerando  che  ogni  parrucchiere  impiega  mediamente  15 
minuti per ogni cliente.    
 
Vogliamo  poi  implementare  una  seconda  classe,  CodaDalParrucchiereAccurata,  in  cui  i 
meccanismi di prenotazione restano invariati ma la stima dell’attesa prende in considerazione anche 
la velocità media di lavoro del parrucchiere (minuti impiegati per un cliente). A tal fine, il costruttore 
di questa nuova classe riceve in input una map<string,unsigned>, dove ogni chiave 
rappresenta  un  parrucchiere  e  il  valore  corrispondente  indica  il  numero  di  minuti  con  cui  il 
parrucchiere, in media, processa un singolo cliente. In questa nuova classe terremo in 
considerazione questo nuovo dato per stimare i tempi d’attesa con maggiore accuratezza. 
 Si noti che la scelta delle strutture dati usate per risolvere l’esercizio ne influenza (positivamente o negativamente) la valutazione. 
*/

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
                        // se la posizione e' < 3, la prenotazione e' imminente 
                        // e non puoi cancellarla
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

            // se trovato e posizione >= 3, e' stato cancellato
            if (trovato && posizione >= 3){return true;}
            // se trovato ma posizione < 3, non e' cancellato
            if(trovato){return false;}

            }
            // cliente non trovato
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