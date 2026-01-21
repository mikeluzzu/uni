#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector<int> bfsPercorso(const Grafo& g, int start, int end) {
    int n = g.n();
    vector<int> padre(n, -1);
    queue<int> q;

    q.push(start);
    padre[start] = start;
    bool trovato = false;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == end) {
            trovato = true;
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (g(u, i) && padre[i] == -1) {
                padre[i] = u;
                q.push(i);
            }
        }
    }
    if (!trovato) return {}; // return vettore vuoto
    
    vector<int> path;
    int curr = end;
    while (curr != start) {
        path.push_back(curr);
        curr = padre[curr];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

vector<int> percorsoTreNodi(const Grafo& g, int c, int b, int v) {
    vector<int> parte1 = bfsPercorso(g, c, v);
    if (parte1.empty()) return {};
    
    vector<int> parte2 = bfsPercorso(g, v, b);
    if (parte2.empty()) return {};
    
    for (size_t i = 1; i < parte2.size(); ++i) {
        parte1.push_back(parte2[i]);
    }
    return parte1;
}