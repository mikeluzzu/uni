// chiedere all'utente due numeri e stampare i nnumeri da 1 a 100, ma interrompere il ciclo se si raggiunge, durante l'iterazione, la somma dei due numeri forniti dall'utente

#include <iostream>
using namespace std;

int main(){
	cout << "inserisci due numeri: \n";
	int n1, n2;
	cin >> n1 >> n2;
	int somma = n1 + n2;
	for(int i = 1; i <= 100; i++){
		cout << i << endl;
		if (i == somma){
			break;
		}
	
	}
	return 0;
}
