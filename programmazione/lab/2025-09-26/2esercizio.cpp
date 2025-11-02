#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> //possiamo accedere al numero piu piccolo o grande rappresentabile
using namespace std;

int main(){
		/*
		// for
		int n;
		int max = INT_MIN;
		int subMax = INT_MIN;

		for (int i=0; i<10; i++){
			cout << "inserisci un numero:\n";
			cin >> n;
			if (n > max){
				subMax = max; //aggiorno il submax
				max = n;      // aggiorno il max
			}
			else if (n > subMax){
				subMax = n;   //aggiorno il subMax
			}
		}
		cout << "massimo: " << max << endl;
		cout << " sottomassimo" << subMax << endl;
		*/

		// while
		int n;
		int max = INT_MIN;
		int subMax = INT_MIN;
	 	int i;
		while (i < 5){
			cout << "inserisci un numero";
			cin >> n;
			if (n>max){
				subMax = max; //aggiorno il submax
				max = n;      // aggiorno il max
			}
		}
	return 0;
}

