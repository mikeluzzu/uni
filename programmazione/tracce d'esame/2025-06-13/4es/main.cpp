#include<iostream>
#include<vector>

using namespace std;

// Funzione ricorsiva per trovare il ciclo hamiltoniano
bool trovaCiclo(const Grafo& g, int nodoCorrente, int nodoIniziale, 
                vector<bool>& visitati, vector<int>& cammino, int numVisitati) {
    // Caso base: abbiamo visitato tutti i nodi
    if (numVisitati == g.n()) {
        // Controlliamo se esiste un arco dal nodo corrente al nodo iniziale
        if (g(nodoCorrente, nodoIniziale)) {
            cammino.push_back(nodoIniziale); // Aggiungiamo il nodo iniziale per chiudere il ciclo
            return true;
        }
        return false;
    }
    
    // Proviamo a visitare tutti i nodi adiacenti non ancora visitati
    for (int i = 0; i < g.n(); i++) {
        if (g(nodoCorrente, i) && !visitati[i]) {
            // Segniamo il nodo come visitato
            visitati[i] = true;
            cammino.push_back(i);
            
            // Ricorsione per continuare il cammino
            if (trovaCiclo(g, i, nodoIniziale, visitati, cammino, numVisitati + 1)) {
                return true;
            }
            
            // Backtracking: rimuoviamo il nodo se non porta a una soluzione
            visitati[i] = false;
            cammino.pop_back();
        }
    }
    
    return false;
}

void esercizio4(const Grafo& g) {
    // Caso particolare: grafo vuoto
    if (g.n() == 0) {
        cout << "Impossibile" << endl;
        return;
    }
    
    // Caso particolare: un solo nodo (deve esistere un self-loop)
    if (g.n() == 1) {
        if (g(0, 0)) {
            cout << "0 0" << endl;
        } else {
            cout << "Impossibile" << endl;
        }
        return;
    }
    
    // Proviamo a partire da ogni nodo del grafo
    for (int nodoIniziale = 0; nodoIniziale < g.n(); nodoIniziale++) {
        vector<bool> visitati(g.n(), false);
        vector<int> cammino;
        
        // Segniamo il nodo iniziale come visitato
        visitati[nodoIniziale] = true;
        cammino.push_back(nodoIniziale);
        
        // Cerchiamo un ciclo hamiltoniano partendo da questo nodo
        if (trovaCiclo(g, nodoIniziale, nodoIniziale, visitati, cammino, 1)) {
            // Stampiamo il cammino trovato
            for (int i = 0; i < cammino.size(); i++) {
                if (i > 0) cout << " ";
                cout << cammino[i];
            }
            cout << endl;
            return;
        }
    }
    
    // Nessun ciclo hamiltoniano trovato
    cout << "Impossibile" << endl;
}