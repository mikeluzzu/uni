// stampare i numeri da 1 a 20 che sono divisibili per 3

#include<iostream>
using namespace std;

int main(){
	for(int i = 1; i <= 20; i++){
		if (i % 3 == 0){
			cout << i << endl;
		}
	}
	return 0;
}
