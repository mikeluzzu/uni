#include <iostream>
#include "telefonata.h" 
using namespace std;


int main(){
	
	Orario in(2,3,45);
	Orario fin(2,4,65);
	Telefonata t(in,fin, 98374298);
	cout << t.durata();
}
