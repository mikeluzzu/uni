#include "Dipendente.h"
#include "GestoreDipendenti.h"
#include <iostream>

using namespace std;

int main(){
	// test classe Dipendente

	Dipendente d1 = Dipendente();
	Dipendente d2 = Dipendente("AAA", "Michele", "Molinaro", 3000.0);
	
	d1.setId("BBB");
	d1.setStipendio(3500.0);
	
	cout << d1 << endl << d2 << endl;

	// test classe Gestore DIpendenti

	GestoreDipendenti gd = GestoreDipendenti();

	// test esisteDipendente()

	string id = "AAA";
	cout << "Esiste dipendente con ID = " << id << "? " << gd.esisteDipendente("AAA") << endl;

	//test aggiungiDipendente()

	gd.aggiungiDipendente(d1);
	gd.aggiungiDipendente(d2);
	cout << "Esiste dipendente con ID = " << id << "? " << gd.esisteDipendente("AAA") << endl;

	// test calcolaCostoDipendenti()
	cout << "In totale, lo stipendio di tutti i dipendenti è: " << gd.calcolaCostoDipendenti() << "€" << endl;
	
	// test rimuoviDipendente()
	gd.rimuoviDipendente("CCCC");  // non rimuove niente poichè non esiste dipendente con id "CCCC";
	cout << "GestoreDipendenti dopo rimozione di \"CCCC\": " << endl << gd << endl;
	
	gd.rimuoviDipendente("AAAA");
	cout << "GestoreDipendenti dopo rimozione di \"AAAA\": " << endl;
	gd.stampa(); // test stampa()
	
	return 0;
	
}
