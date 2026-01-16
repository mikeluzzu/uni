#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

// Verifica se una cella è nella scacchiera
bool inScacchiera(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

// Verifica se una regina in (r, c) è minacciata da un'altra regina
bool reginaMinacciata(int r, int c, const vector<pair<int,int>>& regine, 
                      const set<pair<int,int>>& alfieri, int n) {
    // Direzioni: orizzontale, verticale, diagonali
    int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
    
    for(int dir = 0; dir < 8; dir++) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        // Scorro in questa direzione
        while(inScacchiera(nr, nc, n)) {
            // Se trovo un alfiere mi fermo (blocca la minaccia)
            if(alfieri.count({nr, nc})) break;
            
            // Se trovo una regina, sono minacciata
            for(auto& reg : regine) {
                if(reg.first == nr && reg.second == nc) {
                    return true;
                }
            }
            
            nr += dr[dir];
            nc += dc[dir];
        }
    }
    return false;
}

// Verifica se una regina in (r, c) è minacciata da un alfiere
bool minacciataAlfiere(int r, int c, const set<pair<int,int>>& alfieri, int n) {
    // Direzioni diagonali
    int dr[] = {1, 1, -1, -1};
    int dc[] = {1, -1, 1, -1};
    
    for(int dir = 0; dir < 4; dir++) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        
        while(inScacchiera(nr, nc, n)) {
            if(alfieri.count({nr, nc})) {
                return true;
            }
            nr += dr[dir];
            nc += dc[dir];
        }
    }
    return false;
}

// Verifica quali alfieri sono minacciati dalle regine
set<pair<int,int>> alferiMinacciati(const vector<pair<int,int>>& regine,
                                      const set<pair<int,int>>& alfieri, int n) {
    set<pair<int,int>> minacciati;
    
    for(auto& reg : regine) {
        // Direzioni diagonali (le uniche in cui la regina minaccia alfieri)
        int dr[] = {1, 1, -1, -1};
        int dc[] = {1, -1, 1, -1};
        
        for(int dir = 0; dir < 4; dir++) {
            int nr = reg.first + dr[dir];
            int nc = reg.second + dc[dir];
            
            while(inScacchiera(nr, nc, n)) {
                if(alfieri.count({nr, nc})) {
                    minacciati.insert({nr, nc});
                    break;
                }
                nr += dr[dir];
                nc += dc[dir];
            }
        }
    }
    return minacciati;
}

// Backtracking per posizionare k regine
bool risolvi(int numRegine, int k, vector<pair<int,int>>& regine,
             const set<pair<int,int>>& alfieri, int n, int startR, int startC) {
    
    // Caso base: ho posizionato tutte le k regine
    if(numRegine == k) {
        // Verifico che tutti gli alfieri siano minacciati
        set<pair<int,int>> minacciati = alferiMinacciati(regine, alfieri, n);
        return minacciati.size() == alfieri.size();
    }
    
    // Provo a posizionare una regina in ogni cella
    for(int r = startR; r < n; r++) {
        int colInizio = (r == startR) ? startC : 0;
        
        for(int c = colInizio; c < n; c++) {
            // Verifico che la cella sia libera
            if(alfieri.count({r, c})) continue;
            
            // Verifico che non sia minacciata
            if(reginaMinacciata(r, c, regine, alfieri, n)) continue;
            if(minacciataAlfiere(r, c, alfieri, n)) continue;
            
            // Posiziono la regina
            regine.push_back({r, c});
            
            // Ricorsione
            if(risolvi(numRegine + 1, k, regine, alfieri, n, r, c + 1)) {
                return true;
            }
            
            // Backtrack
            regine.pop_back();
        }
    }
    
    return false;
}