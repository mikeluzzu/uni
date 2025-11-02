//Chiedere all'utente due numeri, num1 e num2. Stampare i numeri da 1 fino a num1, ma interrompere il ciclo se si raggiunge num2

#include <iostream> 
using namespace std;

int main(){
	cout << "inserisci due numeri\n";
	int n1,n2;
	cin >> n1 >> n2;
	for (int i = 1; i < n1; i++){
		if(i == n2){
			break;
		}
		cout << i << endl;
	}
return 0;
}
