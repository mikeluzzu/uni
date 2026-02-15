
bool f(const Grafo& g){
    int n = g.n();
    int m = g.m();

    if(m % 2 != 0) 
        return false;

    for(int i = 0; i < n; i++){
        if(g(i,i)) 
            return false;
    }


    // trovo tutti i nodi con archi entranti
    int gradi_entranti[n];
    for(int j = 0; j < n; j++)
        gradi_entranti[j] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g(i,j))
                gradi_entranti[j]++;
        }
    }

    // trovo i nodi con massimo 1 arco entrante
    int nodi_1_entrante = 0;
    for(int j = 0; j < n; j++){
        if(gradi_entranti[j] <= 1){
            nodi_1_entrante++;
        }
    }

    // trovo il grado uscente di ogni nodo
    for(int i = 0; i < n; i++){
        int grado_uscente = 0;
        for(int j = 0; j < n; j++){
            if(g(i,j))
                grado_uscente++;
        }
        // se il grado uscente, controllato per ogni nodo, e' maggiore, allora return false
        if (grado_uscente >= nodi_1_entrante)
            return false
    }
    return true;
}