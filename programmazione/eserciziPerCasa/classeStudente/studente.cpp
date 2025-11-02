#include<iostream>
#include<vector>
using namespace std;


class Data{
};

class Studente{
	private:
		int matricola;
		int numeroEsami;
		vector<int> esamiSostenutiNonSuperati;
		vector<int> esamiSuperati;
	public:
		// costruttore senza parametri. Esami default di una triennale
		Studente(){
			numeroEsami = 21; 
		}

		// costruttore con 1 parametro
		Studente(int n){
			numeroEsami = n; 
		}
		
		void setMatricola(){
			int inputMatricola;
			cout << "inserisci matricola: " << endl;
			cin >> inputMatricola;
			matricola = inputMatricola;
		}
		
		int getMatricola(){return matricola;}
		
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
		
	   	void getEsamiSuperati(){
			cout << "Esami superati: " << endl;
			for (int i = 0; i<esamiSuperati.size(); i++){
				cout << esamiSuperati[i] << " ";
			}
		}
		
		double getMedia(){
			double somma = 0;
			for(unsigned i = 0; i < esamiSuperati.size(); i++){
				somma+=esamiSuperati[i];
			}
			double media = somma / esamiSuperati.size();
			return media;
		}		

		int getVotoMax(){
			if(esamiSuperati.empty()) return 0;
			int votoMax = esamiSuperati[0];

			for (unsigned i = 1; i < esamiSuperati.size(); i++){
				if (esamiSuperati[i] > votoMax){
					votoMax = esamiSuperati[i];
				} 
			}
		return votoMax;
		}	
};


 
int main(){
	Studente s1(30);
	s1.setVoto();
	s1.setVoto();
	s1.setVoto();
	s1.getEsamiSuperati();




	cout << endl;
	return 0;
}
