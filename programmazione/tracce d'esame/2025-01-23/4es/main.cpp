/*
Su una scacchiera 8x8, il cavallo è un pezzo che si muove ad “L”, spostandosi sempre di una cella in
orizzontale e di 2 in verticale o viceversa, in qualsiasi direzione. I movimenti del cavallo possono
essere codificati dalle seguenti coppie di interi: (-2,-1), (-2,+1), (-1,-2), (-1,+2),
(+1,-2), (+1,+2), (+2, -1), (+2,+1)
Ad esempio, se siamo nella cella di riga 4 e colonna 3, seguendo il primo movimento della lista
finiremo sulla cella (2,2), mentre seguendo il secondo movimento arriveremo in (2,4) e così
via.
Scrivere un programma che prenda in input:
1. la posizione iniziale di un cavallo su scacchiera 8x8 (pair<unsigned,unsigned>)
2. un insieme di caselle proibite (vector<pair<unsigned,unsigned> >)
3. una casella di destinazione (pair<unsigned,unsigned>)
Il programma deve determinare se è possibile far arrivare il cavallo dalla sua posizione iniziale alla
destinazione, considerando che esso non può fermarsi sulle caselle proibite (ma può attraversarle
all’interno di una singola mossa). Naturalmente, non è ammesso che il cavallo si muova al di fuori
della scacchiera. Inoltre, non è possibile che il percorso del cavallo preveda di passare sulla stessa
casella più di una volta. Se esiste una soluzione dovrà stampare in output l’insieme delle caselle da
attraversare per arrivare a destinazione, altrimenti dovrà stampare “IMPOSSIBILE”.

*/

#include <iostream>
#include <vector>

using namespace std;

struct Soluzione{
    // istanza
    pair<unsigned, unsigned> pos_iniziale;
    vector<pair<unsigned, unsigned>> proibite;
    pair<unsigned,unsigned> destinazione;
    vector<pair<int, int>> mosse;  // int e non unsigned perche possiamo avere anche numeri negativi
    pair<unsigned, unsigned> pos_corrente;
    vector<pair<unsigned, unsigned>> visitate;

    // soluzione
    vector<pair<unsigned, unsigned>> soluzione;

    Soluzione(pair<unsigned,unsigned> pi, vector<pair<unsigned,unsigned>> pr, pair<unsigned,unsigned> d)
    : pos_iniziale(pi), proibite(pr), destinazione(d) {
        mosse = {
            {-2,-1}, {-2,+1}, (-1,-2), (-1,+2), (+1,-2), (+1,+2), (+2, -1), (+2,+1);

        visitate = {pos_iniziale};
        soluzione= {
        }
        pos_corrente = pos_iniziale;
        }
    }


};

bool solve(Soluzione& sol){
    int index_mossa = 0;
    while (index_mossa < sol.mosse.size() ){
        if (canAdd(sol.mosse[index_mossa], sol)){
            add.(sol.mosse[index_mossa], sol);
            if (isComplete(sol))
        }
    }
}