#include "studente.h"

int main(){
cout << "inserimento array studenti" << endl;
	cout << "inserire il numero di studenti" << endl;
	
	int numeroStudenti;
	cin >> numeroStudenti;
	vector<Studente> studenti;

	for (int i = 0; i < numeroStudenti; i++){
		cout << "Studente: " << (i+1) << endl;
		Studente s;
		s.leggiStudente();
		studenti.push_back(s);				
	}

	cout << "Elenco studenti: " << endl;
	for (const auto& s : studenti){
		s.stampaStudente();
	}

	cout << endl;
	return 0;
}
