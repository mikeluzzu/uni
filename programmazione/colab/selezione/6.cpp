// leggere l'età di una persona e stampare "minorenne" o "maggiorenne"

#include <iostream>
using namespace std;

int main(){
	int eta;
	cout << "inserisci l'età\n";
	cin >> eta;
	if (eta < 18){
		cout << "minorenne\n";
	}else{
		cout << "maggiorenne\n";
	}
	return 0;
}
