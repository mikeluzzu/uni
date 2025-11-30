#include "GestoreParole.h"
#include <iostream>

using namespace std;

void GestoreParole::leggi() {
	string tmp;
	cin >> tmp;
	while (tmp != "0") {
		parole.push_back(tmp);
		cin >> tmp;
	}
}

bool GestoreParole::ripetizioni() const {
	for (int i=0; i<parole.size(); ++i){
		for(int j=1; j<parole.size(); ++j) {
			if (i!=j && parole[i] == parole[j]){
				return true;
			}
		}
	}
	return false;
}

bool GestoreParole::esisteParola(string parola) const {
	for (int i=0; i<parole.size(); ++i){
		if (parole[i] == parola){
			return true;
		}
	}
	return false;
}

bool GestoreParole::esisteParolaConIniziali(string iniziali) const{
	for (int i=0; i<parole.size(); ++i){
		if (parole[i].find(iniziali) == 0){
			return true;
		}
	}
	return false;
}

void GestoreParole::sostituisciIniziali(string iniziali){
	for (int i=0; i<parole.size(); ++i){
		if (parole[i].size() >= 5){
			parole[i].replace(0,3, iniziali);
		}
	}
}

ostream& operator<<(ostream& os, const GestoreParole& gp){
	for (int i=0; i<gp.getParole().size(); ++i){
		os << gp.getParole()[i] << ' ';
	}
	return os;
}
