//Leggere un numero dall'utente e stampare "Pari" se il numero è divis//ibile per 2, altrimenti stampare "Dispari".
//

#include <iostream>

using namespace std;

int main(){
	cout << "inserisci un numero\n";
	int n;
	cin >> n;
	if (n % 2 == 0){
		cout << "pari" << endl;
	}else{
		cout << "dispari" << endl;
	}
	return 0;
}
