#include "GestoreDipendenti.h"

using namespace std;

bool GestoreDipendenti::esisteDipendente(string id) const {
	for (int i=0; i<dipendenti.size(); ++i){
		if(dipendenti[i].getId() == id){
			return true;
		}
	}
	return false;
}


bool GestoreDipendenti::aggiungiDipendente(Dipendente d){
	if(!esisteDipendente(d.getId())) {
		dipendenti.push_back(d);
		return true;
	}
	return false;

}

void GestoreDipendenti::rimuoviDipendente(string id){
	// con iteratori
	for (auto it = dipendenti.begin(); it != dipendenti.end(); ++it){
		if (it->getId() == id){
			dipendenti.erase(it);
			return;
		}
	}
	
	//versione con indici, non ho capito il funzionamento

	/*
	unsigned int j = 0;
    	for(unsigned int i = 0; i < dipendenti.size(); i++) {
		dipendenti[j] = dipendenti[i];
		if(dipendenti[i].getId() != id)
	    		j++;
    	}
    	dipendenti.resize(j);
	*/	
}

float GestoreDipendenti::calcolaCostoDipendenti() const {
	float tot = 0.0;
	for (int i=0; i<dipendenti.size(); ++i){
		tot += dipendenti[i].getStipendio();
	} 

	return tot;
}

void GestoreDipendenti::stampa() const {
	for (int i=0; i<dipendenti.size(); ++i){
		cout << dipendenti[i];
	}
}

// non necessari aggiunti per esercizio

ostream& operator << (ostream& os, const GestoreDipendenti& gd){
	for (int i=0; i<gd.getDipendenti().size(); ++i){
		os << gd.getDipendenti()[i];
	}
	return os;
}

bool GestoreDipendenti::aggiungiDipendentePerRiferimento(const Dipendente& d){
	if (!esisteDipendente(d.getId())){
		dipendenti.push_back(d);
		return true;
	}
	return false;
}
