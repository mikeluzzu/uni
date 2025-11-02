// leggere una stringa dall'utente e stampare "Si" se la stringa è uguale a "c++", altrimenti stampare no
//
//

#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "inserisci una stringa \n";
	string testo;
	cin >> testo;
	if (testo.find("c++")){
		cout << "si\n";
	}else {
		cout << "no\n";

	}
	return 0;
}
