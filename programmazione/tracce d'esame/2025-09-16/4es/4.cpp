#include <iostream>
#include <vector>

using namespace std;

int N; // Dimensione scacchiera
char board[20][20]; // Scacchiera (dimensione max fissa per comodità su carta)
vector<pair<int, int>> alfieri; // Lista posizioni alfieri

// Funzione per controllare se una cella esiste nella scacchiera
bool inBounds(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

// Controlla se una cella è vista da un pezzo specifico in una direzione
// dr, dc definiscono la direzione (es: 1,0 è giù, -1,-1 è diagonale alto-sx)
bool vedePezzo(int r, int c, int dr, int dc, char target) {
    int i = r + dr;
    int j = c + dc;
    while (inBounds(i, j)) {
        if (board[i][j] == target) return true; // Trovato il pezzo!
        if (board[i][j] != '.') return false;   // Trovato un ostacolo diverso
        i += dr;
        j += dc;
    }
    return false;
}

// Verifica se è sicuro piazzare una Regina in (r, c)
bool isSafe(int r, int c) {
    if (board[r][c] != '.') return false; // Cella occupata

    // Direzioni: 8 possibili (orizzontali, verticali, diagonali)
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++) {
        // Controllo se vedo un'altra REGINA (non posso starci)
        if (vedePezzo(r, c, dr[k], dc[k], 'R')) return false;
        
        // Controllo se vedo un ALFIERE (solo diagonali)
        // Le diagonali hanno indici k: 0, 2, 5, 7 nel mio array, oppure controllo se abs(dr) == abs(dc)
        if (abs(dr[k]) == abs(dc[k])) {
             if (vedePezzo(r, c, dr[k], dc[k], 'A')) return false;
        }
    }
    return true;
}

// Verifica finale: tutti gli alfieri devono essere sotto scacco
bool alfieriMinacciati() {
    for (auto p : alfieri) {
        int r = p.first;
        int c = p.second;
        bool minacciato = false;
        
        // Controllo 8 direzioni dall'alfiere per cercare una Regina
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 
            0, 1};

        for (int k = 0; k < 8; k++) {
            if (vedePezzo(r, c, dr[k], dc[k], 'R')) {
                minacciato = true;
                break;
            }
        }
        if (!minacciato) return false; // Almeno un alfiere è salvo -> soluzione non valida
    }
    return true;
}

// Funzione Backtracking
// index: cella corrente linearizzata (da 0 a N*N-1) per scorrere la scacchiera
bool solve(int k_da_piazzare, int index) {
    // CASO BASE: Ho piazzato tutte le regine
    if (k_da_piazzare == 0) {
        return alfieriMinacciati();
    }
    
    // Se finisco le celle ma ho ancora regine da piazzare
    if (index == N * N) return false;

    int r = index / N;
    int c = index % N;

    // TENTATIVO 1: Metto la regina qui (se posso)
    if (isSafe(r, c)) {
        board[r][c] = 'R'; // Piazzio
        if (solve(k_da_piazzare - 1, index + 1)) return true; // Ricorsione
        board[r][c] = '.'; // Backtrack (tolgo)
    }

    // TENTATIVO 2: Non metto la regina qui, passo alla prossima cella
    if (solve(k_da_piazzare, index + 1)) return true;

    return false;
}

int main() {
    int K; 
    // Immagina cin >> N >> K; e lettura alfieri
    // Inizializza board a '.' e piazza gli alfieri 'A'
    
    if (solve(K, 0)) {
        // Stampa matrice
    } else {
        cout << "IMPOSSIBILE" << endl;
    }
    return 0;
}