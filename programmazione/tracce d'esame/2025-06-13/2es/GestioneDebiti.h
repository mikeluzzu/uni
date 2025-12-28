/*
Una compagnia di amici è rappresentata da un vettore di n stringhe (che si possono supporre tutte 
diverse tra loro). Ogni stringa rappresenta il nome di una persona (e contiene solo lettere minuscole 
dell’alfabeto latino). Il gruppo di amici in questione è solito organizzare serate e cene. Come spesso 
accade, quando si organizzano questo tipo di attività, alcuni componenti del gruppo anticipano le 
spese  di  organizzazione  (per  qualcuno  nello  specifico  o  per  tutto  il  gruppo)  per  poi  riscuotere  il 
denaro dagli amici in un secondo momento. Bisogna tenere traccia di tutte le entrate e uscite per 
una data serata. A tal fine vogliamo implementare una classe GestioneDebiti che tiene traccia 
dei debiti e dei crediti che ognuno ha con tutti gli altri. La classe riceve in input il vettore degli “amici” 
e deve esporre almeno i seguenti metodi: 
- void anticipa(string x, string y, float k) con il quale stiamo dicendo 
che x ha anticipato una spesa  per conto di y di k euro. Se y==”*” significa che la spesa 
sostenuta è da attribuire a tutti (l’importo a deve quindi essere diviso equamente per tutti 
gli amici, compreso x stesso). Ogni  debito  generato  “verso  se  stessi”  verrà  poi 
automaticamente azzerato. 
- float saldo (string x, string y) const che restituisce l’importo che x deve 
restituire ad y in quel dato momento, considerando anche eventuali debiti che  y ha con x, 
calcolandone la differenza. Se tale differenza è minore di 0, saldo deve restituire 0. 
-  void paga (string x, string y, float k) tiene traccia del fatto che x ha 
restituito  k  euro  ad  y.  Questa  operazione  può  essere  effettuata  solo  se  saldo(x,y)  è 
positivo e k è minore o uguale a saldo(x,y). Pertanto, il debito residuo di x verso y sarà 
saldo(x,y)-k, e il debito residuo di y verso x sarà conseguentemente azzerato. 

*/

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