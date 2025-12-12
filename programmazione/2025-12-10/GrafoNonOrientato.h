#ifndef GRAFONONORIENTATO_H_
#define GRAFONONORIENTATO_H_

#include "Grafo.h"
#include <cassert>
#include <vector>

#include<iostream>
using namespace std;
// grafo orientato
// (i,j) != (j,i)

class GrafoNonOrientato : protected Grafo {

public:

    GrafoNonOrientato(unsigned n): Grafo(n){};

    // inserisce o elimina l'arco (i,j) (a seconda del valore di b)
    void operator()(unsigned i, unsigned j, bool b) {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        bool esisteArco = this->archi[i][j];
        if ((!esisteArco && b) || (esisteArco && !b)) {
            this->archi[i][j] = b;  // arco i->j
            this->archi[j][i] = b; // arco j->i (rende il grafo non orientato)
            if (b)
                vm++;
            else
                vm--;
        }
    }

    void svuota(){
        Grafo::svuota();
    }

    unsigned n() const{
        return Grafo::n();
    }
    
    unsigned m() const{
        return Grafo::m();
    }

    bool operator()(unsigned i, unsigned j) const {
        return Grafo::operator()(i,j);
    }

    void stampa(){
        return Grafo::stampa();
    }
    
    int getNodoConGradoMassimo(const GrafoNonOrientato& g){
        int grado_max = -1;
        int nodo_con_grado_max = -1;

        for (int nodo = 0; nodo < g.n(); nodo ++){
            int grado = 0;
            for (int i =0; i <g.n(); i++){
                if (g(nodo,i) && i !=  nodo){
                    grado++;
                }
            }

            if (grado>grado_max){
                grado_max = grado;
                nodo_con_grado_max = nodo;
            }
        }
        return nodo_con_grado_max;
    }
    
};

#endif
