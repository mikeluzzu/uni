#include<iostream>
#include<vector>
using namespace std;

bool trovaCiclo(const Grafo& g, int nodoCorrente, int nodoIniziale, 
                vector<bool>& visitati, vector<int>& cammino, int numVisitati
                )
    if (numVisitati == g.n()){
        if(g(nodoCorrente,nodoIniziale)){
            cammino.push_back(nodoIniziale);
            return true;
        }
        return false;
    }

    for(int i = 0; i < g.n(); i++){
        if(g(nodoCorrente, i) && !visitati[i]){
            visitati[i] = true;
            cammino.push_back(i);

            if(trovaCiclo(g, i, nodoIniziale, visitati, cammino, numVisitati + 1))
                return true

            visitati[i] = false;
            cammino.pop_back();
        }

    return false;
}

void esercizio4(const Grafo& g){
    if(g.n() == 0){
        cout << "Impossibile" << endl;
        return;
    }

    if(g.n() == 1){
        if(g(0,0)) cout << "0 0" << endl;
        else cout << "Impossibile" << endl;
        return;
    }

    for(int nodoIniziale = 0; nodoIniziale < g.n(); nodoIniziale++){
        vector<bool> visitati(g.n(), false);
        vector<int> cammino;

        visitati[nodoIniziale] = true;
        cammino.push_back(nodoIniziale);

        if(trovaCiclo(g, nodoIniziale, nodoIniziale, visitati, cammino, 1)){
            for(int i = 0; i < cammino.size(); i++){
                if(i > 0) cout << " ";
                cout << cammino[i];
            }
            cout << endl;
            return;
        }
    }
    cout << "Impossibile" << endl;
}