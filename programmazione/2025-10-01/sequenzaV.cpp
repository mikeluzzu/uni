/*
Verifica di "Sequenza a V" 
Scrivi un programma in C++ che legge una sequenza di numeri interi positivi forniti dall'utente terminata da -1, verifica se questa è "a V" e stampa il risultato.

Una sequenza è definita "a V" se, dopo il primo elemento, tutti i numeri sono strettamente decrescenti fino a raggiungere un minimo (il "vertice" della V), e da quel punto in poi sono strettamente crescenti fino alla fine.

Vincoli:

1.	La sequenza non deve essere interamente decrescente o interamente crescente. Deve esserci almeno una fase di discesa e una fase di salita.

2.	La sequenza deve avere almeno tre numeri per essere considerata.

Input	
•	10, 5, 2, 4, 7, -1	SI
•	15, 10, 5, -1	NO
•	5, 10, 15, -1	NO
•	10, 5, 5, 7, -1	NO
•	5, 2, 8, 4, -1	NO

*/

#include <iostream>
using namespace std;


int main()
{
    int cont=0; 
    int prec, corr;
    bool decrescente=true;
    bool vertice_trovato=false;
    bool errore=false;
    cout<<"Inserisci una sequenza di numeri terminata da -1"<<endl;
    cin>> corr;
    while(corr!=-1){
        cont++;
        if(cont >1 && !errore){
            if(corr==prec){
                errore=true;
            }
            else if(decrescente){
                
                if(corr>prec){
                    if(cont<3){
                        errore=true;
                    }else{
                        decrescente=false;
                        vertice_trovato=true;
                    }
                }
            } else 
                if(corr<prec){
                errore=true;
                }
        }
        prec=corr;
        cin>>corr;
    }
    
    if(cont<3)
        cout<<"sequenza non valida"<<endl;
    else if(errore ||!vertice_trovato)
        cout<<"sequenza non a V"<<endl;
    else
        cout<<"sequenza a V"<<endl;
    return 0;
}