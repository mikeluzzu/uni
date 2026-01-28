int calcolaDistanzaMinima(const Grafo& g, unsigned s, unsigned t){
    queue<unsigned> q;
    vector<int> dist(g.numNodi(), INF);

    q.push(s);
    dist[s] = 0;

    while (!q.empty()){
        unsigned u = q.front();
        q.pop();

        for (unsigned v : g.adiacenti(u)){
            if (dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t];
}

bool f(const Grafo&g, unsigned s, unsigned t, pair<unsigned,unsigned> edge){
    unsigned i = edge.first;
    unsigned j = edge.second;

    //1. calcola distanza originale (usa una BFSo Dijkstra)

    int distanzaOriginale = calcolaDistanzaMinima(g,s,t);

    // se non esiste un cammino, return false
    if (distanzaOriginale == INF) return false;

    // 2. crea una copia del grafo e modifica l'arco

    Grafo gModificato = g;
    gModificato.rimuoviArco(i,j); // rimuove (i,j)
    gModificato.aggiungiArco(j,i); // aggiunge (j,i), invertito

    // 3. calcola nuova distanza
    int nuovaDistanza = calcolaDistanzaMinima(gModificato, s, t);

    // 4. confronto
    return (nuovaDistanza < distanzaOriginale);
}