#ifndef GESTIONEDEBITI_H
#define GESTIONEDEBITI_H
#include<vector>
#include<string>
using namespace std;

class GestioneDebiti{
private:
    vector<string> amici;
    vector<vector<float>> debiti; // matrice n x n dei debiti
    // funzione helper per trovare l'indice di un amico
    int trovaIndice(const string& nome) const{
        for(int i = 0; i < amici.size(); i++){
            if(amici[i] == nome) return i;
        }
        return -1; // non trovato
    } 

public:
    GestioneDebiti(vector<string>& amici) : amici(amici){
        int n = amici.size();
        // inizializza la matrice dei debiti a 0
        debiti.resize(n,vector<float>(n, 0.0));
    }

    void anticipa(string x, string y, float k){ 
        int idx_x = trovaIndice(x);

        if(y == "*"){
            // x anticipa per tutti (compreso se stesso)
            int n = amici.size();
            float quota = k / n; // divido la spessa per tutti
            
            for (int i = 0; i < n; i++){
                // escludi x stesso
                if(i != idx_x){
                    debiti[i][idx_x] += quota; // l'amico i deve a x
                }
                // il debio di x verso x stesso viene automaticamente ignorato
            }
        }else{
            // x anticipa solo per y
            int idx_y = trovaIndice(y);
            debiti[idx_y][idx_x] += k; // y deve k a x
        }
    }

    float saldo(string x, string y) const {
        int idx_x = trovaIndice(x);
        int idx_y = trovaIndice(y);
        // Calcola il saldo netto: quanto x deve a y meno quanto y deve a x
        float saldoNetto = debiti[idx_x][idx_y] - debiti[idx_y][idx_x];
        // se negativo, restituisci 0
        return max(0.0f, saldoNetto);
    }

    void paga(string x, string y, float k){
        int idx_x = trovaIndice(x);
        int idx_y = trovaIndice(y);

        float saldoAttuale = saldo(x,y);

        // verifica che il pagamento sia valido
        if(saldoAttuale > 0 && k <= saldoAttuale){
            // riduci il debito di x verso y
            debiti[idx_x][idx_y] -= k;
            // il debito di y verso x viene automaticamente considerato nel saldo
        }
    }

};

#endif