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
    // Costruttori
    Studente();
    Studente(int n);
    Studente(string n, string c, int m, Data d);
    
    // Set e Get per la data di nascita
    void setDataNascita(Data d);
    Data getDataNascita() const;
    
    // Altri metodi set/get...
    
    // Metodi I/O
    void leggiStudente();
    void stampaStudente() const;

    //costruttore con 4 parametri
		Studente(string n, string c, int m, int num);

		//getters and setters
		void setMatricola();
		
		int getMatricola();
		
		void setVoto();
		
	   	void getEsamiSuperati();
	
		void getTotaleEsamiSostenuti();
		
		double getMedia();	

		int getVotoMax();

		void getNumEsamiLaurea();
};

#endif