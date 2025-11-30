#ifndef GESTORE_DIPENDENTI_H
#define GESTORE_DIPENDENTI_H

#include "Dipendente.h"
#include <iostream>
#include <vector>


class GestoreDipendenti {
	private:
		vector<Dipendente> dipendenti;
	public:
		GestoreDipendenti() = default;
		GestoreDipendenti(vector<Dipendente> d): dipendenti(d) {}
		
		vector<Dipendente> getDipendenti() const {return dipendenti;} // serve per operator <<

		// metodi principali
		bool esisteDipendente(string id) const;
		bool aggiungiDipendente(Dipendente d);
		void rimuoviDipendente(string id);
		float calcolaCostoDipendenti() const;
		void stampa() const; 
		
		//aggiunto per esercizio
		bool aggiungiDipendentePerRiferimento(const Dipendente& d);

		friend ostream& operator<<(ostream& os, const GestoreDipendenti& gd);
};

#endif
