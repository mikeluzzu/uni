#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minimizeMakespan(vector<int>& p, int m) {
    // Passo 1: Ordina i job in ordine decrescente
    sort(p.begin(), p.end(), greater<int>());
    
    // Passo 2: Min-heap per tenere traccia dei carichi delle macchine
    // pair<carico, id_macchina>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // Inizializza le macchine con carico 0
    for(int i = 0; i < m; i++) {
        pq.push({0, i});
    }
    
    // Passo 3: Assegna ogni job alla macchina meno carica
    for(int job : p) {
        auto [carico, id] = pq.top();
        pq.pop();
        
        // Assegna job a questa macchina
        pq.push({carico + job, id});
    }
    
    // Passo 4: Il makespan è il carico massimo
    int makespan = 0;
    while(!pq.empty()) {
        makespan = max(makespan, pq.top().first);
        pq.pop();
    }
    
    return makespan;
}

int main() {
    vector<int> p = {1, 5, 6, 4, 2};
    int m = 2;
    
    int risultato = minimizeMakespan(p, m);
    cout << "Makespan: " << risultato << endl;
    
    return 0;
}