#ifndef DIPENDENTE_H
#define DIPENDENTE_H

#include <iostream>
#include <string>

using namespace std;

class Dipendente {
	private:
		string id;
		string nome;
		string cognome;
		float stipendio;
	public:
		// costruttori
		Dipendente() : stipendio(0.0) {}
		Dipendente(string i, string n, string c, float s) : id(i), nome(n), cognome(c), stipendio(s) {}

		//getters
		string getId() const {return id;}
		string getNome() const {return nome;}
		string getCognome() const {return cognome;}
		float getStipendio() const {return stipendio;}
		
		//setter
		void  setId(string i) {id = i;}
		void setNome(string n) {nome = n;}
		void setCognome(string c) {cognome = c;}
		void setStipendio(float s) {stipendio = s;}
 
		friend ostream& operator << (ostream& os, const Dipendente& d){
			os << "Id: " << d.id << endl
			   << "Nome: " << d.nome << endl
			   << "Cognome: " << d.cognome << endl
			   << "Stipendio: " << d.stipendio << endl;
			return os;
		}
};

#endif
