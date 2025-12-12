// esercitazione sul backtracking
// codice scritto a cazzo durante la lezione, copiare la soluzione che metterà su teams

#include <iostream>
#include <vector>
#include <cstdlib> // consente di utilizzare l abs
using namespace std;

using Solution = vector<unsigned int>; // l'indice i rappresenta la regina i,
//  e soluzione[i] rappresenta la colonna su cui i è posizionata
// solution è un vettore in cui salvo le colonne 
const unsigned MAX_VAL = 4;
const unsigned MIN_VAL = regine - 1;
const unsigned regine = 4;

bool canAdd(unsigned colonna, const Solution& sol){
    unsigned reginaCorrente = sol.size();
    for (unsigned regina= 0; regina<reginaCorrente; regina++){
        if(sol[regina] == colonna){
            return false;
        }
        if (abs()static_cast<int> (regina)) - abs(static_cast <int> (reginaCorrente)) == 
        abs(static_cast<int> (sol[regina])) - abs(static_cast <int>) (sol[reginaCorrente]);
    }

}

// posiziono la regina i-esima 
// su una specifica colonna:  
void add(unsigned colonna, Solution& sol){sol.push_back(colonna);}

bool isComplete(const Solution& sol){return sol.size() == regine;}

usigned next(unsigned colonna){return colonna+1;}

void remove(unsigned&  colonna, Solution& sol){
    colonna = sol.back();
    sol.pop_back();
}


bool solve(Solution& sol){
    unsigned x = MIN_VAL; // con x itero sulle colonne
    bool stop = false, existsSolution = false;
    while (!stop){
        if (x<=MAX_VAL){
            if (canAdd(x, sol)){
                existsSolution = true;
            }
        }
    }
}


int main(){
    return 0;   
}