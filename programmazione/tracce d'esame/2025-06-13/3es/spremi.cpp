float spremi(AlberoB<float>& tree){
    // caso base: albero nullo
    if (tree.nullo()){ return 0.0f}

    //caso base: nodo foglia, mantiene il suo valore
    if(tree.foglia()){return 0.0f}

    // nodo interno: preleva il valore corrente
    float valore = tree.radice();
    float metaValore = valore / 2.0f;
    float raccolto = 0.0f;

    // imposta il valore del nodo corrente a 0
    tree.modRadice(0.0f);

    // gestione figlio sinistro
    if(!tree.figlio(SIN).nullo()){
        // aggiungi meta del valore al figlio sinistro
        AlberoB<float>& sinistro = tree.figlio(SIN);
        sinistro.modRadice(sinistro.radice() + metaValore);
        // ricorsione sul figlio sinistro
        raccolto += spremi(sinistro);

    } else {
        // figlio sinistro nullo: raccoglie la quantita
        raccolto += metaValore;
    }

    // gestione figlio destro
    if(!tree.figlio(DES).nullo()){
        // Aggiungi meta del valore al figlio destro
        AlberoB<float>& destro = tree.figlio(DES);
        destro.modRadice(destro.radice() + metaValore);
        // ricorsione sul destro
        raccolto += spremi(destro);
    }else{
        // figlo destro nullo: raccoglie la quantita
        raccolto += metaValore;
    }
    return raccolto;
}