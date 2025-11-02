//Leggere due numeri dall'utente e stampare il maggiore dei due.

#include <iostream>
using namespace std;

int main(){
	cout << "inserisci due numeri" << endl;
	int n1,n2;
	cin >> n1 >> n2;
	if (n1 > n2){
		cout << n1 << endl;
	}else{
		cout << n2 << endl;
	}
	return 0;
}
