struct Nodo{
    int valore;
    Nodo* next;
    Nodo(int v) : valore(v), next(nullptr){}
};

bool esisteCammino(Nodo* da, Nodo* a){
    // se ho un solo nodo
    if (da == a) return true;
    // se non esiste il nodo
    if (da == nullptr) return false;
    // prendo il nodo adiacente
    Nodo* adj = da->next;
    while (adj != nullptr){
        if (esisteCammino(adj,a)) return true;
        adj = adj -> next;
    }
}
bool funzione(Nodo* s, Nodo* t){
    return esisteCammino(s,t) && esisteCammino(t,s);
}
