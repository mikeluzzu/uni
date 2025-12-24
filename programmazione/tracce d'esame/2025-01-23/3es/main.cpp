/*
Scrivere una funzione f che, preso in input un Grafo orientato g, restituisca true se e solo se
risultano verificate tutte le seguenti proprietà:
• Il grado uscente di ogni nodo di g è minore del numero di nodi di g che hanno al più un arco
entrante
• Il numero totale di archi di g è pari
• g non ha autoarchi (archi che vanno da un nodo a sé stesso)
La classe Grafo dispone dei seguenti metodi pubblici (dove g è un’istanza della classe Grafo):
• g.n() che restituisce il numero di nodi del Grafo
• g.m() che restituisce il numero di archi del Grafo
• g(i,j) che restituisce true se esiste un arco dal nodo i al nodo j e false altrimenti
Nota: Verrà assegnato un piccolo bonus a chi svolgerà l’esercizio in modo da ‘evitare’, quando possibile, di verificare le condizioni
computazionalmente più onerose (la complessità dei 3 metodi pubblici della classe Grafo è O(1)
*/

#include "Grafo.h"
#include <vector>
using namespace std;

bool f(const Grafo& g) {
    vector<int> grado_uscente(g.n());
    vector<int> grado_entrante(g.n());

    int count_archi=0;

    for (int i=0; i<g.n(); ++i)
        for (int j=0; j<g.n(); ++j) {
            if (g(i, j)) {  
                if (i==j) return false; // CODIZIONE 3: g NON ha autoarchi
                grado_entrante[j]++;    // punto 1
                grado_uscente[i]++;     // punto 1
                count_archi++;          // punto 2
            }
        }
    
    // CONDIZIONE 2. Il numero totale di archi di g è pari
    if (count_archi%2!=0)
        return false;

    // CONDIZIONE 1. il grado uscente di ogni nodo di g è minore del numero di nodi di g che hanno al più un arco entrante
    // conto nodi con al più un arco entrante
    int count_max_uno_entrante=0;
    for (int i=0; i<g.n(); ++i)
        if (grado_entrante[i]<=1)
            count_max_uno_entrante++;
    // controllo che non esista nodo con grado uscente > # nodi con max 1 entrante
    for (int i=0; i<g.n(); ++i)
        if (grado_uscente[i] > count_max_uno_entrante)
            return false;

    return true;      
}

