// //Esercizio 13: Classificazione di un carattere alfabetico
// Chiedi all'utente di inserire un carattere alfabetico. Stampa se è una vocale o una
// consonante

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void carattere(){
	cout << "Inserisci una carattere alfabetico\n";
	string car;
	cin >> car;
	if (car != "a" || car != "e" || car != "i" ||  car != "o" || car != "u"){
	cout << "Consonante" << endl;
	}else if (car == "a" || car == "e" || car == "i" || car == "o" || car == "u"){
	cout << "Vocale" << endl;
	}
}

int main(){
	carattere();
	return 0;
}
