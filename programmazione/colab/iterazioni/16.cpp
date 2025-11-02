// chieddere all'utente un numero e stampare la tabellina del quadrato di quel numero fino a 10

#include <iostream>
#include <cmath>
using namespace std;

int main(){
	cout << "inserisci un numero: \n";
	int numero;
	cin >> numero;
	int quadrato = pow(numero,2);
	

	for (int i = 1; i < 11; i++){
		int risultato = quadrato * i;
		cout << risultato << endl;
	}
return 0;
}
