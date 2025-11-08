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
    
    //costruttore con 4 parametri
    Studente(string n, string c, int m, int num);
	
    // costruttore per copia
    Studente(const Studente& altro);

		//getters and setters
		void setNome();
		void setCognome();
		void setMatricola();
		void setDataNascita();
        void setVoto();

		string getNome();
		string getCognome();
		int getMatricola();
	    Data getDataNascita() const;
	   	void getEsamiSuperati();
		void getTotaleEsamiSostenuti();
		double getMedia();
		int getVotoMax();
		void getNumEsamiLaurea();
		bool studentePiuGiovaneDi();

		// Metodi I/O
		void leggiStudente();
		void stampaStudente() const;

		Studente & operator = (const Studente & altro);
};

#endif
