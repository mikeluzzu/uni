#include "data.h"
#include "studente.h"
using namespace std;

		void Studente::setDataNascita(Data d) {
		dataNascita = d;
	}

	Data Studente::getDataNascita() const {
		return dataNascita;
	}

	void Studente::leggiStudente() {
		cout << "Inserisci nome: ";
		cin >> nome;
		cout << "Inserisci cognome: ";
		cin >> cognome;
		cout << "Inserisci matricola: ";
		cin >> matricola;
		cout << "Inserisci data di nascita:" << endl;
		dataNascita.leggi();  // Chiama il metodo leggi di Data
	}

	void Studente::stampaStudente() const {
		cout << "Nome: " << nome << endl;
		cout << "Cognome: " << cognome << endl;
		cout << "Matricola: " << matricola << endl;
		cout << "Data di nascita: ";
		dataNascita.stampa();  // Chiama il metodo stampa di Data
		cout << endl;
	}



		// costruttore senza parametri. Esami default di una triennale
		Studente::Studente(){
			numeroEsami = 20; 
		}

		// costruttore con 1 parametro
		Studente::Studente(int n){
			numeroEsami = n; 
		}

		//fare il costruttore per copia

		//costruttore con 4 parametri
		Studente::Studente(string n, string c, int m, int num){
			nome = n;
			cognome = c;
			matricola = m;
			numeroEsami = num;
		}

		//getters and setters
		void Studente::setMatricola(){
			int inputMatricola;
			cout << "inserisci matricola: " << endl;
			cin >> inputMatricola;
			matricola = inputMatricola;
		}
		
		int Studente::getMatricola(){return matricola;}
		
		void Studente::setVoto(){
			int voto;
			cout << "inserisci il voto: " << endl;
			cin >> voto;
			if (voto >= 18 && voto <= 30){
				esamiSuperati.push_back(voto);
			}else if (voto >= 1 && voto <= 17){
				esamiSostenutiNonSuperati.push_back(voto);
				
			}
		}
		
	   	void Studente::getEsamiSuperati(){
			cout << "Esami superati: " << endl;
			for (int i = 0; i<esamiSuperati.size(); i++){
				cout << esamiSuperati[i] << " ";
			}
			cout << endl;
		}
	
		void Studente::getTotaleEsamiSostenuti() {
			totaleEsamiSostenuti = esamiSuperati.size() + esamiSostenutiNonSuperati.size();
			cout << "totale esami sostenuti: " << totaleEsamiSostenuti << endl;
		}	
		
		double Studente::getMedia(){
			double somma = 0;
			for(unsigned i = 0; i < esamiSuperati.size(); i++){
				somma+=esamiSuperati[i];
			}
			double media = somma / esamiSuperati.size();
			return media;
		}		

		int Studente::getVotoMax(){
			if(esamiSuperati.empty()) return 0;
			int votoMax = esamiSuperati[0];

			for (unsigned i = 1; i < esamiSuperati.size(); i++){
				if (esamiSuperati[i] > votoMax){
					votoMax = esamiSuperati[i];
				} 
			}
		return votoMax;
		}	

		void Studente::getNumEsamiLaurea(){
			int numEsamiLaurea = numeroEsami - esamiSuperati.size();
			cout << "esami mancanti alla laurea: " << numEsamiLaurea << endl; 
		}


 
