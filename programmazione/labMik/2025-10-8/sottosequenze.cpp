//Leggere due sequenze di interi terminata da -1 e verificare se la seconda è sottosequenza della prima.
//In caso affermativo, restituire la posizione di inizio della sottosequenza.
//Nota: utilizzare array dinamici e puntatori

#include <iostream>
using namespace std;

int main(){
    // Lettura sequenza principale
    int capacita1 = 10;
    int *s1 = new int[capacita1];
    int dim1 = 0;
    
    cout << "Inserisci la sequenza principale (termina con -1): ";
    int valore;
    while(true){
        cin >> valore;
        if(valore == -1) break;
        
        // Espandi array se necessario
        if(dim1 >= capacita1){
            capacita1 *= 2;
            int *temp = new int[capacita1];
            for(int i = 0; i < dim1; i++){
                temp[i] = s1[i];
            }
            delete[] s1;
            s1 = temp;
        }
        s1[dim1++] = valore;
    }
    
    // Lettura sottosequenza
    int capacita2 = 10;
    int *s2 = new int[capacita2];
    int dim2 = 0;
    
    cout << "Inserisci la sottosequenza (termina con -1): ";
    while(true){
        cin >> valore;
        if(valore == -1) break;
        
        if(dim2 >= capacita2){
            capacita2 *= 2;
            int *temp = new int[capacita2];
            for(int i = 0; i < dim2; i++){
                temp[i] = s2[i];
            }
            delete[] s2;
            s2 = temp;
        }
        s2[dim2++] = valore;
    }
    
    // Stampa sequenze
    cout << "\nSequenza principale: ";
    for(int i = 0; i < dim1; i++){
        cout << s1[i] << " ";
    }
    cout << endl;
    
    cout << "Sottosequenza: ";
    for(int i = 0; i < dim2; i++){
        cout << s2[i] << " ";
    }
    cout << endl;
    
    // Ricerca sottosequenza
    bool trovata = false;
    int posizione = -1;
    
    // Scorre la sequenza principale
    for(int i = 0; i <= dim1 - dim2; i++){
        bool match = true;
        // Verifica se la sottosequenza combacia a partire dalla posizione i
        for(int j = 0; j < dim2; j++){
            if(s1[i + j] != s2[j]){
                match = false;
                break;
            }
        }
        if(match){
            trovata = true;
            posizione = i;
            break;
        }
    }
    
    // Risultato
    if(trovata){
        cout << "\nLa sottosequenza e' presente a partire dalla posizione: " << posizione << endl;
    } else {
        cout << "\nLa sottosequenza NON e' presente nella sequenza principale." << endl;
    }
    
    // Libera memoria
    delete[] s1;
    delete[] s2;
    
    return 0;
}
