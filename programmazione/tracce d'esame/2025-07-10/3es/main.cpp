#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

vector<unsigned> bfsPercorso(const Grafo& g, unsigned start, unsigned end) {
    unsigned n = g.n();
    vector<unsigned> padre(n, -1);
    queue<unsigned> q;

    q.push(start);
    padre[start] = start;
    bool trovato = false;
    
    while (!q.empty()) {
        unsigned u = q.front();
        q.pop();
        if (u == end) {
            trovato = true;
            break;
        }
        for (unsigned i = 0; i < n; ++i) {
            if (g(u, i) && padre[i] == -1) {
                padre[i] = u;
                q.push(i);
            }
        }
    }
    if (!trovato) return {}; // return vettore vuoto
    
    vector<unsigned> path;
    unsigned curr = end;
    while (curr != start) {
        path.push_back(curr);
        curr = padre[curr];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

vector<unsigned> percorsoTreNodi(const Grafo& g, unsigned c, unsigned b, unsigned v) {
    vector<unsigned> parte1 = bfsPercorso(g, c, v);
    if (parte1.empty()) return {};
    
    vector<unsigned> parte2 = bfsPercorso(g, v, b);
    if (parte2.empty()) return {};
    
    for (size_t i = 1; i < parte2.size(); ++i) {
        parte1.push_back(parte2[i]);
    }
    return parte1;
}