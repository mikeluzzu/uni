//Stampare tutti i numeri da 100 a 1 che sono divisibili per 4.

#include <iostream>
using namespace std;

int main(){
	for (int i = 100; i > 1; i--){
		if (i % 4 == 0){
			cout << i << endl;
		}
	}
return 0;
}
