#ifndef UNIVERSITA_H
#define UNIVERSITA_H

#include "StudenteDinamico.h"
#include <iostream>
#include <string>

using namespace std;

class Universita{
private:
        string nome;
        StudenteDinamico * studenti;
        int numStudenti;
        int capacita; // capacita attuale dell'array

        void ridimensiona(){
            capacita *= 2;
            StudenteDinamico * nuovoArray = new StudenteDinamico[capacita];
            for(int i = 0; i < numStudenti; i++){
                nuovoArray[i] = studenti[i]
            }
            delete[]studenti;
            studenti = nuovoArray;
        }
public:
        // costtruttore con un parametro
        Universita(const string & n = "Universita senza nome") 
        : nome(n), numStudenti(0), capacita(10) {
            studenti = new StudenteDinamico[capacita];
        }

        //costruttore di copia
        Universita(const Universita& altra)
        : nome(altra.nome), numStudenti(altra.numStudenti), capacita(altra.capacita){
            studenti = new StudenteDinamico[capacita];
            for (int i = 0; i < numStudenti; i++){
                studenti[i] = altra.studenti[i];
            }
        }

        //distruttore
        ~Universita(){delete[] studenti;}

        //operatore di assegnamento
        Universita& operator=(const Universita& altra) {
            if (this != &altra){
                delete[]studenti;

                nome = altra.nome;
                numStudenti = altra.numStudenti;
                capacita = altra.capacita;

                // alloco e copio l array
                studenti = new StudenteDinamico[capacita];
                for (int i = 0; i < numStudenti; i++){
                    studenti[i] = altra.studenti[i];
                }
            }
            return *this;
        }
        
        string getNome() const {return nome;}
        int getNumStudenti() const {return numStudenti;}

        void aggiungiStudente(const StudenteDinamico& s){
            if(cercaStudente(s.getMatricola()) != -1){
                cout << "Attenzione, studente con matricola " << s.getMatricola() << 
                " gia esistente!" << endl;
                return;
            }

            if(numStudenti >= capacita){ridimensiona();}

            studenti[numStudenti] = s;
            numStudenti++;
            cout << "Studente aggiunto con successo!" << endl;
        }

        int cercaStudente(int matricola) const {
            for(int i = 0; i < numStudenti; i++){
                if (studenti[i].getMatricola() == matricola){
                    return i;
                }
            }
            return -1;
        }

        bool rimuoviStudente(int matricola){
            int indice = cercaStudente(matricola);

            if(indice == -1){
                cout << "Studente con matricola " << matricola << " non trovato!" << endl;
                return false;
            }

            // spostamento degli elementi successivi indietro di 1 posizione
            for (int i = indice; i < numStudenti - 1; i++){
                studenti[i] = studenti[i+1];
            }
            numStudenti--;
            cout << "Studente con matricola " << matricola << " rimosso con successo!" << endl;
            return true;
        }

        //get studente - restituisce uno studente per matricola
        StudenteDinamico getStudente(int matricola) const {
            int indice = cercaStudente(matricola);

            if (indice == -1){
                cout << "errore: studente con matricola " << matricola << " non trovato" << endl;
                return StudenteDinamico();
            }
            return studenti[indice];
        }
        
        bool setStudente(int matricola, const StudenteDinamico& s){
            int indice = cercaStudente(matricola);
            if(indice == -1) {
            cout << "Errore: studente con matricola " << matricola << " non trovato!" << endl;
            return false;
        }
        
            studenti[indice] = s;
            cout << "Dati studente aggiornati con successo!" << endl;
            return true;
        }

         // migliorStudente - restituisce lo studente con la media più alta
    StudenteDinamico migliorStudente() const {
        if(numStudenti == 0) {
            cout << "Nessuno studente presente nell'università!" << endl;
            return StudenteDinamico();
        }
        
        int indiceMigliore = 0;
        float mediaMigliore = studenti[0].getMedia();
        
        for(int i = 1; i < numStudenti; i++) {
            float mediaCorrente = studenti[i].getMedia();
            if(mediaCorrente > mediaMigliore) {
                mediaMigliore = mediaCorrente;
                indiceMigliore = i;
            }
        }
        
        return studenti[indiceMigliore];
    }


    // Operatore di output
    friend ostream& operator<<(ostream& out, const Universita& uni) {
        out << "========================================" << endl;
        out << "Università: " << uni.nome << endl;
        out << "Numero studenti iscritti: " << uni.numStudenti << endl;
        out << "========================================" << endl;
        
        if(uni.numStudenti == 0) {
            out << "Nessuno studente iscritto." << endl;
        } else {
            for(int i = 0; i < uni.numStudenti; i++) {
                out << "\n--- Studente " << (i+1) << " ---" << endl;
                out << uni.studenti[i];
            }
        }
        out << "========================================" << endl;
        
        return out;
    }
};

#endif