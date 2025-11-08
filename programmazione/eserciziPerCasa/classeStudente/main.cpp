#include "studente.h"

int main(){
	Studente s1;
/* 	for (int i = 1; i <= 5; i++){
		s1.setVoto();
	}
	s1.getEsamiSuperati();
	s1.getTotaleEsamiSostenuti();
	s1.getNumEsamiLaurea();
        s1.getVotoMax(); */
	
	cout << "inserimento array studenti" << endl;
	s1.setNome();
	s1.setCognome();
	s1.setMatricola();
	s1.setData(26,10,2005);	
	s1.getNome();
	s1.getCognome();
	s1.getMatricola();
	s1.getDataNascita();
	s1.stampaStudente();
	cout << endl;
	return 0;
}
