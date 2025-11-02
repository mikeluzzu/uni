// stampare i primi 10 numeri interi positivi e la loro somma

#include<iostream>
using namespace std;

int main(){
	int somma = 0;

	for(int i = 1; i < 11; i++){
		somma += i;
		cout << i << endl;
	}
	cout << "la somma totale è: " <<  somma << endl;
	return 0;
}
