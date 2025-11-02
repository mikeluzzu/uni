//Definire una lista numeri contenente i numeri da 1 a 5. Stampare la lista.
#include <iostream>
using namespace std;

int main(){
	int *lista = nullptr; 
	lista = new int[5];
	for (int i = 0; i < 5; i++){
		lista[i];
	}    

	for (int i = 0; i < 5; i++){
		cout << lista[i];
	}
	return 0;

}
