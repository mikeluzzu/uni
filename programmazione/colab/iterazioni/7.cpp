// chiedere all'utente una parola e stamparla n volte, dove n è la lunghezza della parola

#include<iostream>
#include<string>

using namespace std;

int main(){
	cout << "iserisci una parola\n"; 
	string parola;
	cin >> parola;
	int len = parola.size();
	for(int i = 1; i <= len; i++){
		cout << i << " " <<  parola << endl;
	
	}
	return 0;
}
