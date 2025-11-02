#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){	
	
	const int MAX = 100;
	int arr[MAX];
	int n = 0;
	
	//input dei numeri
	int num;
	cout << "inserisci numeri: \n";
	while (cin >> num && num != -1 && n < MAX){
		arr[n++] = num;
	}
	
	//compattazione dell'array (rimuovo duplicati)
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n;){
			if (arr[i] == arr[j]){
				// elimina arr[j] spostando a sinistra
				for (int k = j; k < n-1; k++){
					arr[k] = arr[k + 1];
				}
				n--; //diminuisco la lunghezza
			}else {
				j++; //solo se non ce stato uno spostamento		
			}
		}
	}
	cout << "l'array compattato e: \n";
	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "la nuova lunghezza e': \n" << n << endl;
	
	return 0;
	
}
