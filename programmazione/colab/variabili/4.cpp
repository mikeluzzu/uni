//Definire una variabile numero con il valore 100. Convertire il numero in una
 //stringa e stampare il risultato.

#include <iostream>
#include <string>
using namespace std;
int main(){
	int n = 100;
	string result = to_string(n);
	cout << result << sizeof(result) << endl;
	return 0;
}
