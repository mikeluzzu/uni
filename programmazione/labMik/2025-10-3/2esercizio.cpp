#include <iostream>
using namespace std;

int main(){
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	int massimo = 0;
	int len = sizeof(array) / sizeof(array[0]);
	
	for(int i = 1; i < len; i++){
		if (array[i] > massimo){
			massimo = array[i];
		}
	}
	for (int i = 0; i < len; i++){
		int differenza;
		differenza = massimo - array[i];
		cout << "numero: " << array[i] << " differenza: " << differenza << endl; 
	}
	cout << massimo << endl;
return 0;	
}
