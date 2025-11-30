#include "Dipendente.h"

// costruttori
		Dipendente() : stipendio(0.0) {}; 
		Dipendente::Dipendente(string i, string n, string c, float s) : id(i), nome(n), cognome(c), stipendio(s) {}
		//getters
		string Dipendente::getId() const {return id;}
		string Dipendente::getNome() const {return nome;}
		string Dipendente::getCognome() const {return cognome;}
		float Dipendente::getStipendio() const {return stipendio;}
		
		//setter
		void Dipendente::setId(string i) {id = i;}
		void Dipendente::setNome(string n) {nome = n;}
		void Dipendente::setCognome(string c) {cognome = c;}
		void Dipendente::setStipendio(float s) {stipendio = s;}
 
		friend Dipendente::ostream& operator << (ostream& os, const Dipendente& d){
			os << "Id: " << d.id << endl
			   << "Nome: " << d.nome << endl
			   << "Cognome: " << d.cognome << endl
			   << "Stipendio: " << d.stipendio << endl;
			return os;
		}