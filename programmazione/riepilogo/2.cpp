#include <iostream>
using namespace std;

class NumeroRazionale{
    private:
        int numeratore;
        int denominatore;

    public:
        // costruttore senza paramentri
        NumeroRazionale(){
            numeratore = 0;
            denominatore = 1;
            cout << numeratore << "/" << denominatore << endl;
        }
	
	//costruttore con 1 parametro
	NumeroRazionale(int n){
		numeratore = n;
		denominatore = 1;
		cout << numeratore << "/" << denominatore << endl;
	}

        //costruttore con 2 parametri
         NumeroRazionale(int n, int d){
            numeratore = n;
            denominatore = d;
	    cout << numeratore << "/" << denominatore << endl;
        }
	

	// costruttore copia
	NumeroRazionale(const NumeroRazionale & copia){
		numeratore = copia.numeratore;
		denominatore = copia.denominatore;
		cout << numeratore << "/" << denominatore << endl;
	}
	
	//operator ==
	bool operator==(const NumeroRazionale & altro) const {
		return (numeratore  == altro.numeratore && denominatore == altro.denominatore);
	}

	// operatore + come metodo della classe
	NumeroRazionale operator + (const NumeroRazionale& altro) const {
		int n = numeratore * altro.denominatore + denominatore * altro.numeratore;
		int d = denominatore * altro.denominatore;
		return NumeroRazionale(n,d);
	}
	
	//dichiarazione dentro la funzione con friend	
	friend ostream& operator << (ostream& os, const NumeroRazionale& numero);
	friend istream& operator >> (istream& is, NumeroRazionale& numero);
};

	// operatore di output
	ostream& operator << (ostream& os, const NumeroRazionale& numero){
		os << numero.numeratore << "/" << numero.denominatore;
		return os;
}

	//operatore di input
	istream& operator >> (istream& is, NumeroRazionale& numero){
		cout << "inserisci il numeratore: " << endl;
		is >> numero.numeratore;
		cout << "inserisci il denominatore: " << endl;
		is >> numero.denominatore;6
		return is;
}
int main(){
    NumeroRazionale n1;
    NumeroRazionale n2(2);
    NumeroRazionale n3(5,10);
    NumeroRazionale n4 = n3;
    if (n2 == n3){ cout << "sono uguali" << endl;}else{cout << "sono diversi" << endl;}
    if (n3 == n4) {cout << "sono uguali" << endl;} else {cout << "sono diversi" << endl;} 
    
    NumeroRazionale n5(12,8);
    cout << "il numero e':" << n5 << endl;
    
    NumeroRazionale n6;
    cin >> n6;
    cout << n6 << endl;	
	NumeroRazionale n7(1,2);
	NumeroRazionale n8(1,4);
	NumeroRazionale n9 = n7 + n8;
    return 0;
}

