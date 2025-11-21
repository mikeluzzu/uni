#ifndef STUDENTE_DINAMICO_H
#define STUDENTE_DINAMICO_H
#include "Data.h"
using namespace std;
#include <vector>

class StudenteDinamico{

    private:
            int matricola;
            Data dataNascita;
            vector<int> esPassato;
            vector<int> esNonPassato;
    public:
            StudenteDinamico() = default;

            void setMatricola(int & m){matricola = m;}
            int getMatricola() const {return matricola;}

            void setEsame(){
                int voto;
                cout << "Inserisci voto esame: " << endl;
                cin >> voto;
                if (esPassato.size()<=25){
                    if (voto >= 18 && voto <= 30){
                    esPassato.push_back(voto);
                    }
                    else if(voto >=1 && voto <= 17){
                        esNonPassato.push_back(voto);
                    }
                }else{
                    cout << "Numero massimo di voti raggiunto, sei laureato" << endl;
                }    
            }

            int getEsNonPassato(int & v) const {
                for (int i = esNonPassato.begin(); i!= esNonPassato.end(); ++i){
                    if (esNonPassato[i]==v){
                        cout << "Voto trovato: " << endl;
                        return esNonPassato[i];
                    }
                }
                cout << "voto non trovato, riprova" << endl;
                return;
            }

            int getEsPassato(int & v) const {
                for (int i = esPassato.begin(); i!=esPassato.end(); ++i){
                    if (esPassato[i] == v){
                        cout << "Voto trovato: " << endl;
                        return esPassato[i];
                    }
                }
                return;
            }

            void setDataNascita(const Data &d){dataNascita = d;}

            void getDataNascita() const {return dataNascita;}

            float getMedia(){
                float somma = 0;
                for(int i = esPassato.begin(); i!=esPassato.end(); ++i){
                    somma += esPassato[i];
                }
                return somma / esPassato.size();
            }

            int getNumEsamiLaurea()const{
                return 25 - esPassato;
            }

            
};



#endif