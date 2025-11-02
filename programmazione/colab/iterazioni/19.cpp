// Chiedere all'utente un numero e calcolare il fattoriale di quel numero.

#include <iostream>
using namespace std;

int main(){
	cout << "inserisci un numero\n";
	int n;
	int fatt = 1;
	cin >> n;
	
	for (int i = 2; i < n; i++){
		fatt *= i;  
	}
	cout << fatt << endl;
}
