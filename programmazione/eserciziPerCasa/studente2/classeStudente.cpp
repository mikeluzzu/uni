#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Costruttore default

class Studente{
        private:

            string nome;
            string cognome;
            int matricola;
            int numeroEsami;
            int totaleEsamiSostenuti;
            vector<int> esamiSostenutiNonSuperati;
            vector<int> esamiSuperati;

			int giorno;
        	int mese;
        	int anno;

			bool isValida() const {
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
        public:
		// costruttore senza parametri. Esami default di una triennale
		Studente() : numeroEsami(20), giorno(1), mese(1), anno(1900), matricola(0), totaleEsamiSostenuti(0) {}

		// costruttore con 1 parametro
		Studente(int n) : numeroEsami(n), giorno(1), mese(1), anno(1900), matricola(0), totaleEsamiSostenuti(0) {}


		//costruttore per copia
		Studente(const Studente& altro){
		nome = altro.nome;
        cognome = altro.cognome;
        matricola = altro.matricola;
        numeroEsami = altro.numeroEsami;
        giorno = altro.giorno;
        mese = altro.mese;
        anno = altro.anno;
        esamiSuperati = altro.esamiSuperati;
        esamiSostenutiNonSuperati = altro.esamiSostenutiNonSuperati;
        totaleEsamiSostenuti = altro.totaleEsamiSostenuti;
		}
		//costruttore con 4 parametri
		Studente(string n, string c, int m, int num) 
        : nome(n), cognome(c), matricola(m), numeroEsami(num),
          giorno(1), mese(1), anno(1900), totaleEsamiSostenuti(0) {}
    
		//getters and setters

		void setNome(){
			cout << "Inserisci il nome: " << endl;
			cin >> nome;
		}
		void setCognome(){
			cout << "Inserisci il cognome: " << endl;
			cin >> cognome;
 		}
		void setMatricola(){
			cout << "inserisci matricola: " << endl;
			cin >> matricola;
		}
		
		void setDataNascita(){
			cout << "Inserisci data di nascita:" << endl;
        	leggiData();
		}
		
		void setVoto(){
			int voto;
			cout << "inserisci il voto: " << endl;
			cin >> voto;
			if (voto >= 18 && voto <= 30){
				esamiSuperati.push_back(voto);
			}else if (voto >= 1 && voto <= 17){
				esamiSostenutiNonSuperati.push_back(voto);				
			}
		}

		string getNome()const {return nome;}
		string getCognome()const {return cognome;}
		int getMatricola()const {return matricola;}
		
		void getDataNascita(){
			stampaData();
		}

	   	void getEsamiSuperati() const{
			cout << "Esami superati: " << endl;
			for (size_t i = 0; i<esamiSuperati.size(); i++){
				cout << esamiSuperati[i] << " ";
			}
			cout << endl;
		}
	
		void getTotaleEsamiSostenuti() {
			totaleEsamiSostenuti = esamiSuperati.size() + esamiSostenutiNonSuperati.size();
			cout << "totale esami sostenuti: " << totaleEsamiSostenuti << endl;
		}	
		
		double getMedia() const {
			if (esamiSuperati.empty()) return 0.0;

			double somma = 0;
			for(size_t i = 0; i < esamiSuperati.size(); i++){
				somma+=esamiSuperati[i];
			}
			double media = somma / esamiSuperati.size();
			return media;
		}		

		int getVotoMax() const {
			if(esamiSuperati.empty()) return 0;
			int votoMax = esamiSuperati[0];

			for (size_t i = 1; i < esamiSuperati.size(); i++){
				if (esamiSuperati[i] > votoMax){
					votoMax = esamiSuperati[i];
				} 
			}
		return votoMax;
		}	

		void getNumEsamiLaurea() const {
			int numEsamiLaurea = numeroEsami - esamiSuperati.size();
			cout << "esami mancanti alla laurea: " << numEsamiLaurea << endl; 
		}
	
		bool studentePiuGiovaneDi(const Studente & S) const {
			if (anno != S.anno) return anno > S.anno;
			if (mese != S.mese) return mese > S.mese;
			return giorno > S.giorno;
		}
		
		void leggiStudente() {

		cout << "Inserisci nome: ";
		cin >> nome;
		cout << "Inserisci cognome: ";
		cin >> cognome;
		cout << "Inserisci matricola: ";
		cin >> matricola;
		cout << "Inserisci data di nascita:" << endl;
		leggiData();
		
	
		}

		void stampaStudente() const {
			cout << "Nome: " << nome << endl;
			cout << "Cognome: " << cognome << endl;
			cout << "Matricola: " << matricola << endl;
			cout << "Data di nascita: ";
			stampaData();
			cout << endl;
		}
		
		Studente& operator=(const Studente& altro) {
        if (this == &altro) {
            return *this;
        }
        
        nome = altro.nome;
        cognome = altro.cognome;
        matricola = altro.matricola;
        numeroEsami = altro.numeroEsami;
        giorno = altro.giorno;
        mese = altro.mese;
        anno = altro.anno;
        esamiSuperati = altro.esamiSuperati;
        esamiSostenutiNonSuperati = altro.esamiSostenutiNonSuperati;
        totaleEsamiSostenuti = altro.totaleEsamiSostenuti;
        
        return *this;
    }


		//metodi per la data
		void setGiorno (int g) {giorno = g;}
		void setMese(int m) {mese = m;}
		void setAnno(int a) {anno = a;}

		int getGiorno() const {return giorno;}
		int getMese() const {return mese;}
		int getAnno() const {return anno;}

		void leggiData() {
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

		void stampaData() const {
			if (giorno < 10) cout << "0";
			cout << giorno << "/";
			if (mese < 10) cout << "0";
			cout << mese << "/" << anno;
		}
};

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
