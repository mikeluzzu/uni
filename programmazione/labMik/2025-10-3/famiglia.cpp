#include <iostream>
#include <vector>
using namespace std;

int main(){
  // seq = {7,3,0,5,1,7,4,0,2,0,0,3,9,0,-1};
   int nFamiglie = 0;
   int maxFamiglia = 0;
   int maxTemp = 0;
   vector<int> lista = {};
   for (int i = 1, n; n != -1; i++){
		cout << "inserisci un numero:\n";
		cin >> n;
		lista.push_back(n);
		if (n != 0){
			maxTemp++;
			continue;
		}else if (n == 0){
			nFamiglie++;
			if (maxTemp>maxFamiglia){
				maxFamiglia = maxTemp;
				maxTemp = 0;
			}
			continue;
		}
		
	}

	for (int i : lista){

		cout << i << " ";
	}
	cout << endl;
	cout << nFamiglie << endl;
	cout << maxFamiglia << endl;
return 0;   
}
