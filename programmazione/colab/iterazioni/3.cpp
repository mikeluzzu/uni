// chiedere all'utente un numero e stampare tutti i numeri da 0 a quel numero

#include <iostream>
using namespace std;

int main(){
	cout << "inserisci un numero intero\n"; 
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++){
		cout << i << endl;
	}
	return 0;
}
