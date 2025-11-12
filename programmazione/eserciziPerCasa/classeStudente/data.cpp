#include "data.h"

// Costruttore default
Data::Data() {
    giorno = 1;
    mese = 1;
    anno = 1900;
}

// Costruttore con parametri
Data::Data(int g, int m, int a) {
    giorno = g;
    mese = m;
    anno = a;
    
    if (!isValida()) {
        cout << "Attenzione: data non valida, impostata a 01/01/1900" << endl;
        giorno = 1;
        mese = 1;
        anno = 1900;
    }
}

// Metodo privato per validare la data
bool Data::isValida() const {
        if (anno < 1900 || anno > 2100) return false;
        if (mese < 1 || mese > 12) return false;

        int giorniMese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Controllo anno bisestile
        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
            giorniMese[1] = 29;
        }
        if (giorno < 1 || giorno > giorniMese[mese - 1]) return false;

        return true;
}

// Metodi set
//metodi per la data
		void Data::setGiorno (int g) {giorno = g;}
		void Data::setMese(int m) {mese = m;}
		void Data::setAnno(int a) {anno = a;}

		int Data::getGiorno() const {return giorno;}
		int Data::getMese() const {return mese;}
		int Data::getAnno() const {return anno;}

		void Data::leggiData() {
				do {
					cout << "Inserisci il giorno: ";
					cin >> giorno;
					cout << "Inserisci il mese: ";
					cin >> mese;
					cout << "Inserisci l'anno: ";
					cin >> anno;
					
					if (!isValida()) {
						cout << "Data non valida! Riprova." << endl;
					}
				} while (!isValida());
			}

		void Data::stampaData() const {
			if (giorno < 10) cout << "0";
			cout << giorno << "/";
			if (mese < 10) cout << "0";
			cout << mese << "/" << anno;
		}