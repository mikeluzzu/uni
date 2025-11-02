//Chiedere all'utente un numero e sommare tutti i numeri da 1 a quel numero. 

#include <iostream>

using namespace std;

int main(){
	cout << "inserisci un numero\n";
	int numero;
	int somma = 0;
	cin >> numero;
	
	for(int i = 1; i <= numero; i++){
		somma += i;
	}
	cout << somma << endl;
return 0;
}
