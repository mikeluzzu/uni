#include<vector>
using namespace std;

bool stessiEntranti(const Grafo& g, int x, int y){
    int n = g.n();
    for (int k = 0; k < n; k++){
        if (g(k,x) != g(k,y)){
            return false;
        }
    }
    return true;
}

bool stessiUscenti(const Grafo& g, int x, int y){
    int n = g.n();
    for (int k = 0; k < n; k++){
        if(g(x,k) != g(y,k)) {
            return false;
        }
    }
    return true;
}

//funzione principale
vector<pair<int,int> trovaNodiSovrapponibili(const Grafo& g){
    vector<pair<int,int>> risultato;
    int n = g.n();

    for (int x= 0; x < n; x++){
        for (int y = 0; y < n; y++){
            if(stessiEntranti(g, x, y) && stessiUscenti(g,x, y)){
                risultato.push_back(make_pair<x,y>);
            }
        }
    }
    return risultato;
}