#include "GestoreParole.h"
#include <iostream>

using namespace std;

int main(){
	GestoreParole gp = GestoreParole();
	
	// test leggi()
	cout << "inserisci delle parole separate da spazio (0 per terminare): ";
	gp.leggi(); // provate anche senza terminare con '0' come dicevamo oggi e vedete cosa succede
	
	// test ripetizioni()
	bool esito = gp.ripetizioni();
	cout << "Ci sono ripetizioni? " << esito << endl;
	
	// test esisteParola()
	string parola = "ciao";
	bool esiste = gp.esisteParola(parola);
	cout << "Esiste \"" << parola << "\"? " << esiste << endl;
	
	// test esisteParolaConIniziali() 
	string iniziali = "ded";
	esiste = gp.esisteParolaConIniziali(iniziali);
	cout << "Esiste parola con iniziali = \"" << iniziali << "\"? " << esiste << endl;
	
	// test sostituisciIniziali()
	cout << "Prima di sostituire con iniziali: " << gp << endl;
	gp.sostituisciIniziali(iniziali);
	cout << "Dopo aver sostituito con iniziali: " << gp << endl;
	
	return 0;
}

