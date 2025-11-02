#include "orario.h" //non posso togliere questo include
#include <iostream>

unsigned Orario::convertiInSecondi()const{return ore *3600 + minuti*60 + secondi}


ostream& operator << (ostream& os, const Orario& O {
	os<< O.ore << ":" << O.minuti << ":" << O.secondi;
}
