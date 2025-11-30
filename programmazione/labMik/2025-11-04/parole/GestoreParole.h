#ifndef GESTORE_PAROLE_H
#define GESTORE_PAROLE_H
#include <vector>
#include <string>

using namespace std;

class GestoreParole{
	private:
		vector<string> parole;
	public:
		GestoreParole() = default;
		GestoreParole(vector<string> p) : parole(p){}

		vector<string> getParole()  const {return parole;}

		//metodi richiesti
		void leggi();
		bool ripetizioni() const;
		bool esisteParola(string parola) const;
		bool esisteParolaConIniziali(string iniziali)  const;
		void sostituisciIniziali(string iniziali);

		friend ostream& operator<<(ostream& os, const GestoreParole& gp);
};


#endif
