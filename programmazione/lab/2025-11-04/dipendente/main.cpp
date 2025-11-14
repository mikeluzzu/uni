#include <iostream>
#include <vector>
using namespace std;

class Dipendente{
	private:
		string id;
		string nome;
		string cognome;
		float stipendio;
	
	public:
		// Costruttore
		Dipendente() : stipendio(0.0) {}
		Dipendente(string i, string n, string c, float s): id(i), nome(n), cognome(c), stipendio(s) {}
		
		// getter
		string getId() const {return id;}
		string getNome() const {return nome;}
		string getCognome() const {return cognome;}
		float getStipendio() const {return stipendio;}
		
		// setter
		void setId(string i) {id=i;}
		void setNome(string n) {nome=n;}
		void setCognome(string c) {cognome=c;}
		void setStipendio(float s) {stipendio=s;}
		
	friend ostream& operator<<(ostream& os, const Dipendente& d) {
		os << "Id: " << d.id << endl
		   << "Nome: " << d.nome << endl
		   << "Cognome: " << d.cognome << endl
		   << "Stipendio: " << d.stipendio << endl
		   << "--------------------" << endl;
		return os;
	}
		
};


class GestoreDipendenti {
	private:
		vector<Dipendente> dipendenti;
	public:
		GestoreDipendenti() = default;
		GestoreDipendenti(vector<Dipendente> d): dipendenti(d) {}
		
		vector<Dipendente> getDipendenti() const {return dipendenti;} // serve per operator <<

		// metodi principali
		bool esisteDipendente(string id) const;
		bool aggiungiDipendente(Dipendente d);
		void rimuoviDipendente(string id);
		float calcolaCostoDipendenti() const;
		void stampa() const; 
		
		//aggiunto per esercizio
		bool aggiungiDipendentePerRiferimento(const Dipendente& d);

		friend ostream& operator<<(ostream& os, const GestoreDipendenti& gd);
};

int main(){
	// test classe Dipendente

	Dipendente d1 = Dipendente();
	Dipendente d2 = Dipendente("AAA", "Michele", "Molinaro", 3000.0);
	
	d1.setId("BBB");
	d1.setStipendio(3500.0);
	
	cout << d1 << endl << d2 << endl;

	// test classe Gestore DIpendenti

	GestoreDipendenti gd = GestoreDipendenti();

	// test esisteDipendente()

	string id = "AAA";
	cout << "Esiste dipendente con ID = " << id << "? " << gd.esisteDipendente("AAA") << endl;

	//test aggiungiDipendente()

	gd.aggiungiDipendente(d1);
	gd.aggiungiDipendente(d2);
	cout << "Esiste dipendente con ID = " << id << "? " << gd.esisteDipendente("AAA") << endl;

	// test calcolaCostoDipendenti()
	cout << "In totale, lo stipendio di tutti i dipendenti è: " << gd.calcolaCostoDipendenti() << "€" << endl;
	
	// test rimuoviDipendente()
	gd.rimuoviDipendente("CCCC");  // non rimuove niente poichè non esiste dipendente con id "CCCC";
	cout << "GestoreDipendenti dopo rimozione di \"CCCC\": " << endl << gd << endl;
	
	gd.rimuoviDipendente("AAAA");
	cout << "GestoreDipendenti dopo rimozione di \"AAAA\": " << endl;
	gd.stampa(); // test stampa()
	
	return 0;
	
}
