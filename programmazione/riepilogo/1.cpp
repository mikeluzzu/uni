#include <iostream>
using namespace std;

bool inizializza(bool * array,int dim){
    array = new bool[dim];
    for (int i = 0; i < dim; i++){
        array[i] = false;
    }
    return array, dim;
}

void stampa(bool arrayNumeri&, int dim&){
	aggiungiElemento(arrayNumeri,dim);
	for (int i=0; i < dim; i++){
		if (arrayNumeri[i]==true){
						
		}
	}	
}

bool aggiungiElemento(bool arrayNumeri&, int dim&){

    int arrayNumeri = new int[dim];
    for (int i=0; i<dim; i++){
        cout << "Inserisci un numero: \n";
        int numero;
        cin >> numero;
    }
    int i = 0;
    while(i <= dim){ 
        nuovoArray[i] = numero;
       i++;
    }
    return arrayNumeri;
}

void dealloca(bool arrayNumeri&){
    delete [] arrayNumeri;
}


int main(){
aggiungiElemento();

dealloca();

}
