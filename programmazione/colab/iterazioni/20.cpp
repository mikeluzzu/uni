//Chiedere all'utente un numero tra 1 e 10 e stampare tutti i numeri da 1 a 100, ma interrompere il ciclo quando si trova un multiplo del numero fornito dall'utente a eccezione del numero stesso

#include <iostream>
using namespace std;

int main(){
	cout << "inserisci un numero da 1 a 10\n";
	int n;
	cin >> n;
	
	for(int i = 1; i < 101; i++){
		if(n % i == 0){
			break;
		}else{
			cout << i << endl;
		}
	}
}
