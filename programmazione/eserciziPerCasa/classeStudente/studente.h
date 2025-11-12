#ifndef STUDENTE_H
#define STUDENTE_H

#include "data.h"


class Studente {
private:
		string nome;
		string cognome;
		int matricola;
		Data dataNascita;
		int numeroEsami;
		int totaleEsamiSostenuti;
		vector<int> esamiSostenutiNonSuperati;
		vector<int> esamiSuperati;
    
public:
    		Studente() : numeroEsami(20), giorno(1), mese(1), anno(1900), matricola(0), totaleEsamiSostenuti(0) {}

		// costruttore con 1 parametro
		Studente(int n) : numeroEsami(n), giorno(1), mese(1), anno(1900), matricola(0), totaleEsamiSostenuti(0) {}


		//costruttore per copia
		Studente(const Studente& altro);
		//costruttore con 4 parametri
		Studente(string n, string c, int m, int num);
    
		//getters and setters

		void setNome();
		void setCognome();
		void setMatricola();
		
		void setDataNascita();
		void setVoto();

		string getNome()const;
		string getCognome()const;
		int getMatricola()const;
		
		void getDataNascita();

	   	void getEsamiSuperati() const;
	
		void getTotaleEsamiSostenuti();
		
		double getMedia() const;	

		int getVotoMax() const;	

		void getNumEsamiLaurea() const;
	
		bool studentePiuGiovaneDi(const Studente & S);
		
		void leggiStudente();

		void stampaStudente() const;
		
		Studente& operator=(const Studente& altro);

};

#endif
