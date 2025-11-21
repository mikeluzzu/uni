#ifndef GESTORE_VEICOLI_H
#define GESTORE_VEICOLI_H

#include <vector>
#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"

using namespace std;


class GestoreVeicoli {
    private: 
        vector<Veicolo*> veicoli;

        void aggiungiVeicolo(Veicolo* v) {
            // controlla che non esista già un veicolo con la stessa targa di v

            //per ogni puntatore nel vettore veicoli, preso dalla classe base Veicolo, controllo se la targa è stata gia aggiunta
            for (Veicolo* ptr : veicoli)
                if (ptr->getTarga() == v->getTarga()) {
                    cout << "Impossibile aggiungere veicolo: targa già esistente" << endl;
                    return;
                }
            // se non trova la targa allora è un veicolo nuovo e lo aggiungo        
            veicoli.push_back(v);
            cout << "veicolo aggiunto correttamente" << endl;
            return;
        }
        

        void clear() {
            while (!veicoli.empty()) {
                delete veicoli.back();  // libera la memoria
                veicoli.pop_back();     // elimina il ptr nel vector
            }            
        }

    public:
        GestoreVeicoli(){}
        // creo una nuova automobile e la aggiungo tramite la aggiungiVeicolo(a) 
        void aggiungiAutomobile(string t, float p, string c, string n) {
            Veicolo* a = new Automobile(t, p, c, n);
            aggiungiVeicolo(a);
        }
        // creo una nuova moto e la aggiungo tramite aggiungiVeicolo(m)
        void aggiungiMoto(string t, float p, string c, string n) {
            Veicolo* m = new Moto(t, p, c, n);
            aggiungiVeicolo(m);
        }

        vector<Veicolo*> getVeicoli() const {
            return veicoli;
        }

        // con il puntatore alla classe faccio il get di un veicolo specifico nel vettore
        Veicolo* getVeicolo(const string& targa) const {
            for (Veicolo* v : veicoli)
                if (targa == v->getTarga())
                    return v;
            return NULL;
        }

        // distruttore per pulire la memoria allocata
        ~GestoreVeicoli() {
            clear();
        }

        // operatore di assegnamento
        GestoreVeicoli& operator=(const GestoreVeicoli& other) {
            if (this != &other) {
                clear();  // reset del vector di veicoli per sicurezza
                for (Veicolo* v : other.veicoli)
                    this -> veicoli.push_back(v->clone());
            }
            return *this;
        }

        // costruttore per copia
        GestoreVeicoli(const GestoreVeicoli& other) {
            for (Veicolo* v : other.veicoli)
                this->veicoli.push_back(v->clone());  // copia profonda di ogni veicolo
        }

};


#endif