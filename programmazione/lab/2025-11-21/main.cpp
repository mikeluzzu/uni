#include <iostream>
#include "Universita.h"
#include "StudenteDinamico.h"
#include "Data.h"
using namespace std;

void menu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Aggiungi studente" << endl;
    cout << "2. Rimuovi studente" << endl;
    cout << "3. Cerca studente" << endl;
    cout << "4. Stampa università" << endl;
    cout << "5. Mostra studente migliore" << endl;
    cout << "0. Esci" << endl;
    cout << "Scelta: ";
}

int main() {
    // 1. Crea un oggetto Università
    string nomeUni;
    cout << "Inserisci il nome dell'università: ";
    getline(cin, nomeUni);
    Universita uni(nomeUni);
    
    int scelta;
    
    do {
        menu();
        cin >> scelta;
        cin.ignore(); // Pulisce il buffer
        
        switch(scelta) {
            case 1: {
                // 2. Permetti all'utente di inserire nuovi studenti
                cout << "\n=== AGGIUNGI STUDENTE ===" << endl;
                StudenteDinamico nuovoStudente;
                cin >> nuovoStudente;
                uni.aggiungiStudente(nuovoStudente);
                break;
            }
            
            case 2: {
                // 3. Prova di rimozione
                cout << "\n=== RIMUOVI STUDENTE ===" << endl;
                int matricola;
                cout << "Inserisci la matricola dello studente da rimuovere: ";
                cin >> matricola;
                uni.rimuoviStudente(matricola);
                break;
            }
            
            case 3: {
                cout << "\n=== CERCA STUDENTE ===" << endl;
                int matricola;
                cout << "Inserisci la matricola dello studente da cercare: ";
                cin >> matricola;
                int indice = uni.cercaStudente(matricola);
                if(indice != -1) {
                    cout << "Studente trovato alla posizione " << indice << endl;
                    StudenteDinamico s = uni.getStudente(matricola);
                    cout << s;
                } else {
                    cout << "Studente non trovato!" << endl;
                }
                break;
            }
            
            case 4: {
                // 4. Stampa l'intero contenuto dell'università
                cout << "\n=== STAMPA UNIVERSITÀ ===" << endl;
                cout << uni;
                break;
            }
            
            case 5: {
                // 5. Identifica e stampa lo studente migliore
                cout << "\n=== STUDENTE MIGLIORE ===" << endl;
                if(uni.getNumStudenti() > 0) {
                    StudenteDinamico migliore = uni.migliorStudente();
                    cout << "Lo studente migliore dell'ateneo è:" << endl;
                    cout << migliore;
                } else {
                    cout << "Nessuno studente presente!" << endl;
                }
                break;
            }
            
            case 0:
                cout << "Arrivederci!" << endl;
                break;
                
            default:
                cout << "Scelta non valida!" << endl;
        }
        
    } while(scelta != 0);
    
    return 0;
}