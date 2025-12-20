/*
Si scriva un programma C++ che, preso in input un insieme di interi non neg-
ativi terminato dal valore -1 e un intero somma target, controlli se esiste un
sottoinsieme di elementi la cui somma sia proprio uguale a somma target.
Stampare un sottoinsieme qualsiasi con tale caratteristica, se esiste, altrimenti
stampare ”nessuna soluzione”
*/

#include<iostream>
#include<vector>
using namespace std;


struct Soluzione{
    vector<int> sol;
    vector<int> elementi;
    int sommaTarget;

    Soluzione(vector<int>& el, int st) : elementi(el), sommaTarget(st){}
};

void add(int x, Soluzione& soluzione){
    soluzione.sol.push_back(x);
}

void remove(int x, Soluzione& soluzione){
    soluzione.sol.pop_back(x);
}


int main(){



    return 0;
}