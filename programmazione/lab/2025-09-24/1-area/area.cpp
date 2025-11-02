// Esercizio 1. Chiedi all'utente di inserire la base e l'altezza di un rettangolo. Calcola e stampa l'area.

#include<iostream>
using namespace std;

void calcolaArea(){
	int base;
	int altezza;
	int area;

	cout << "Inserisci la base: \n";
	cin >> base;
	cout << "Inserisci l'altezza: \n";
	cin >> altezza;

	area = base * altezza;
	cout << "L'area del rettangolo è: " << area << endl;

}

int main(){
	calcolaArea();
	return 0;
}
