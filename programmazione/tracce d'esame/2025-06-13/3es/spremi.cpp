float spremi(AlberoB<float>& tree){
    if(tree.nullo()){return 0.0f}
    if(tree.foglia()){return 0.0f}

    float valore = tree.radice();
    float metaValore = valore / 2.0f;
    float raccolto = 0.0f;
    tree.modRadice(0.0f);

    if(!tree.figlio(SIN).nullo()){
        AlberoB<float>& sinistro = tree.figlio(SIN);
        sinistro.modRadice(sinistro.radice() + metaValore);
        raccolto += spremi(sinistro);
    } else {
        raccolto += metaValore;
    }

    if(!tree.figlio(DES).nullo()){
        AlberoB<float>& destro = tree.figlio(DES);
        destro.modRadice(destro.radice() + metaValore);
        raccolto += spremi(destro);
    } else {
        raccolto += metaValore;
    }
    return raccolto;
}