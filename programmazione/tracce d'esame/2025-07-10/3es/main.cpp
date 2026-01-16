#include <vector>
#include <queue>
#include <algorithm> // per std::reverse

using namespace std;

// --- FUNZIONE AUSILIARIA: Trova percorso minimo da 'start' a 'end' ---
vector<int> bfsPercorso(const Grafo& g, int start, int end) {
    int n = g.n();
    
    // Vettore per tenere traccia dei padri. 
    // padre[i] contiene il nodo da cui siamo arrivati a i.
    // Inizializzato a -1 (che significa "non visitato").
    vector<int> padre(n, -1);
    
    queue<int> q;
    
    // Setup iniziale
    q.push(start);
    padre[start] = start; // Segniamo lo start come visitato (padre di se stesso)
    
    bool trovato = false;
    
    // Ciclo BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == end) {
            trovato = true;
            break; // Arrivati a destinazione
        }
        
        // Esploriamo i vicini. 
        // L'interfaccia g(u, i) ci obbliga a controllare tutti i nodi da 0 a n-1
        for (int i = 0; i < n; ++i) {
            // Se esiste l'arco (u -> i) E i non è ancora visitato
            if (g(u, i) && padre[i] == -1) {
                padre[i] = u; // Memorizziamo da dove veniamo
                q.push(i);
            }
        }
    }
    
    // Se non abbiamo trovato il nodo 'end', restituiamo vuoto
    if (!trovato) return {};
    
    // Ricostruzione del percorso (Backtracking dal nodo 'end' al nodo 'start')
    vector<int> path;
    int curr = end;
    while (curr != start) {
        path.push_back(curr);
        curr = padre[curr];
    }
    path.push_back(start);
    
    // Il percorso è al contrario (end -> ... -> start), quindi lo giriamo
    reverse(path.begin(), path.end());
    
    return path;
}

// --- FUNZIONE RICHIESTA DALL'ESERCIZIO ---
vector<int> percorsoTreNodi(const Grafo& g, int c, int b, int v) {
    // 1. Calcola percorso da c a v
    vector<int> parte1 = bfsPercorso(g, c, v);
    
    // Se non esiste, inutile continuare
    if (parte1.empty()) return {};
    
    // 2. Calcola percorso da v a b
    vector<int> parte2 = bfsPercorso(g, v, b);
    
    // Se non esiste, inutile continuare
    if (parte2.empty()) return {};
    
    // 3. Unione dei due percorsi
    // parte1 è tipo: [c, x, y, v]
    // parte2 è tipo: [v, z, w, b]
    // Dobbiamo evitare di duplicare 'v' centrale.
    
    // Aggiungiamo parte2 alla fine di parte1, saltando il primo elemento di parte2 (che è v)
    for (size_t i = 1; i < parte2.size(); ++i) {
        parte1.push_back(parte2[i]);
    }
    
    return parte1;
}