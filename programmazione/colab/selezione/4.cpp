// Leggere un numero dall'utente e verificare se è compreso tra 1 e 10//Stampare "Dentro l'intervallo" se è compreso, altrimenti "Fuori dall//'intervallo"


#include <iostream>

using namespace std;

int main(){
	cout << "inserisci un numero" << endl;
	int n;
	cin >> n;

	if (n > 1 && n < 10){
		cout << "dentro l'intervallo" << endl;
	}else{
		cout << "fuori l'intervallo" << endl;
	}
	return 0;	
}
