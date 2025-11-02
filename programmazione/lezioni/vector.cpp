#include <iostream>
#include <vector>
using namespace std;
int main(){
	
	vector<int> V = {1,2,3,4,5}; // vector inizializzato

	for (unsigned i=0; i < V.size(); i++){
		cout << V[i] << endl;
	}
 	cout << V.size();
	
	V.push_back(27);
	

	for(vector<int>:: const_iterator it = V.begin(); it != V.end(); it++){
		cout << *it << " ";
		cout << "la size è " << V.size();
	}
		
}
