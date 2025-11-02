// stamapare i numeri da 1 a 50, saltare i multipli di 5

#include <iostream>
using namespace std;

int main(){
	for (int i=1; i < 51; i++){
		if (i % 5 == 0){
			continue;	
		}else{
			cout << i << endl;
		}
	}
}

