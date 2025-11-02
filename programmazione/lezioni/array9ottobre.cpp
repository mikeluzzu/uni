// lezione 9 ottobre
// array multidimensionali
#include <iostream>
using namespace std;


int main(){
    int A[10][10]; // matrice 10x10
    int B[3][3] = {{1,2,3},{1,2,3}}   //inizializzo la matrice 3x3

    // scorro la matrice B
    for (unsigned i=0; i<3; i++){
        for (unsigned j = 0; j < 3; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int ** M = new int* [3]; //creo un puntatore di puntatore, array iniziale
    for (unsigned i=0; i<3; i++){
        M[i] = new int [3]; //per ogni elemento dell'array creo un'array
        
        for(unsigned i=0; i<3; i++){
            for(unsigned j=0; j<3;j++){
                cout << M[i][j]<< " ";
            }
        }
    }

    for (unsigned i=0; i<3; i++){
        delete [] M[i]; //elimino ogni puntatore che punta ad ogni riga

    }
    delete []M; // elimino l'oggetto dinamico puntato da M

    // come creo un array lo devo eliminare, tutti gli elementi che creo nell'
    // heap li vanno eliminati manualmente per evitare i memory leak
    // prima di distruggere M devo distruggere ogni elemento di M
    // quindi prima delete[] M[i] e poi delete[]M;

     
    return 0;
}
