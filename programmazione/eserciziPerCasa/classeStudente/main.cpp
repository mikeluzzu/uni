#include "studente.h"

int main(){
	Studente s1;
	for (int i = 1; i <= 5; i++){
		s1.setVoto();
	}
	s1.getEsamiSuperati();
	s1.getTotaleEsamiSostenuti();
	s1.getNumEsamiLaurea();
    s1.getVotoMax();

	cout << endl;
	return 0;
}
