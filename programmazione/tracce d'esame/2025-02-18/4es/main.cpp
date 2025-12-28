#include<vector>
#include<iostream>
using namespace std;

bool risolviMinesweeper(vector<vector<int>>& pf, int k){
    int n = pf.size();
    vector<pair<int,int>> celleIndeterminate;
    int bombeAttuali = 0;

    // trovo le celle indeterminate e conto le bombe esistenti
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (pf[i][j] == 9){
                celleIndeterminate.push_back({i,j});
            }else if (pf[i][j] == -1){
                bombeAttuali++;
            }
        }
    }


    // calcolo quante bombe rimangono da piazzare 
    int bombeRimanenti = k - bombeAttuali;

    // backtracking
    return backtrack(pf, celleIndeterminate, 0, bombeRimanenti, n);

}

bool backtrack(vector<vector<int>>& pf, vector<pair<int,int>>& celle, int idx, int bombeRimanenti, int n){
    // caso base: tutte le celle sono state assegnate
    if(idx == celle.size()){
        // verifica che abbiamo usato esattemaente k bombe
        if(bombeRimanenti != 0) return false;
        //verifica che tutti i vincoli sono soddisfatti
        return verificaVincoli(pf,n);
    }

    int i = celle[idx].first;
    int j = celle[idx].second;

    // opzione 1: metti una bomba in (i,j)
    if (bombeRimanenti > 0){
        pf[i][j] = -1;
        if (backtrack(pf,celle, idx + 1, bombeRimanenti - 1, n)){return true;} 
    }

    // opzione 2: metti un numero in (i,j)
    int conta = contaBombeAdiacenti(pf,i,j,n);
    pf[i][j] = conta;
    if(backtrack(pf,celle,idx + 1, bombeRimanenti,n)){return true;}

    // backtrack: ripristina valore indeterminato

    pf[i][j] = 9;
    return false;
}

//conta bombe adiacenti

int contaBombeAdiacenti(vector<vector<int>>& pf, int i, int j, int n){
    int conta = 0;
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int k = 0; k < 8; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < n && pf[ni][nj] == -1){
            conta++;
        }
    }
    return conta;
}

// verifica che tutti i numeri rispettino i vincoli imposti

bool verificaVincoli(vector<vectro<int>>& pf, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (pf[i][j] >= 0 && pf[i][j] <= 8){
                int conta = contaBombeAdiacenti(pf,i,j,n);
                if(conta != pf[i][j]) return false;
            }
        }
    }
    return true;
}