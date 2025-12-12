#include"Mobile.h"
#include <list>
#include<vector>
#include<algorithm>

class Mobilificio
{
  list<Mobile> mobili;
  bool ProduceSolo(const string & Produttore, Tipo t);

public:
  bool aggiungi(const Mobile & m)
  {mobili.push_back(m);
   return true;}

  int metodo1(list<Mobile>& mobili){
    /*METODO 1
     Sia X la media dei prezzi di tutti i mobili. Determinare il massimo
     prezzo fra quelli che hanno un prezzo minore o uguale a X.
     Per il calcolo della media utilizzare la divisione intera.
     Se non sono presenti mobili, restituire -1.
    */ 

    for (size_t i = 0; i < mobili.size(); i++){
      if (mobili.empty()){
        cout << "Nessun mobile disponibile" << endl;
        return -1;
      }
      int somma = 0;
      int massimo = mobili[0];
      for (size_t i = 0; i < mobili.size(); i++){
          somma += mobili.getPrezzo();
          if (mobili.getPrezzo() > massimo){
            massimo = mobili.getPrezzo();
          }
      }
      media = somma / mobili.size();
      cout << "Massimo prezzo: " << massimo << endl;
      cout << "Media dei prezzi: " << media << endl;
      return massimo;
    }

  }
  int metodo2(list<Mobile>& mobili){
    /////METODO 2
  /*Per ogni produttore P sia M(P) il prezzo medio dei mobili prodotti da P.
  Un produttore si dice economico se produce solo mobili che costano meno
  del prezzo medio M(P) di ogni *altro* produttore.
  Attenzione: Il prezzo dei prodotti del produttore economico E non e' 
  mai confrontato con la media M(E) (cioe' e' confrontato con tutti 
  tranne che con se stesso).

  Il metodo restituisce il numero di mobili prodotti dal *primo* produttore 
  economico della lista.

  Per il calcolo della media utilizzare la divisione intera.

  Se non sono presenti mobili oppure se nessun produttore verifica la condizione 
  oppure se c'e' un solo produttore,
   restituire -1.
*/

    if (mobili.empty()){
      return -1;
    }

    // 1. calcola la media dei prezzi per ogni produttore

    map<string, int> sommaPrezzi;
    map<string, int> numeroProdotti;
    map<string, int> mediaProduttore;

    for(const Mobile& m : mobili){
      string prod = m.getProduttore();
      sommaPrezzi[prod] += m.getPrezzo();
      numeroProdotti[prod]++;
    }

    // calcola le medie (divisione intera) 
    for (const auto & coppia : sommaPrezzi){
      string prod = coppia.first;
      mediaProduttore[prod] = sommaPrezzi[prod] / numeroProdotti[prod];
    }
    
    // se c'è un solo produttore, restiuisci -1 
    if (mediaProduttore.size() == 1){return -1;}

    // 2. trova il primo produttore economico nella lista
    set<string> produttoriGiaVisitati; // traccio i produttori gia controllati

    for (const Mobile& m : mobili){
      string candidato == m.getProduttore();

      // se abbiamo gia controllato questo produttore, salta

      if (produttoriGiaVisitati.find(candidato) != produttoriGiaVisitati.end()){continue;}

      produttoriGiaVisitati.insert(candidato);

      // 3. verifica se il candidato è economico

      bool isEconomico = true; 

      // controlla tutti i mobili del candidato

      for (const Mobile& mobileCandidato : mobili){
        if(mobileCandidato.getProduttore() != candidato){continue;}
      }

      int prezzoCandidato = mobileCandidato.getPrezzo();

      //confronta con la media di tutti gli altri produttori

      for (const auto& coppia : mediaProduttore){
        string altroProduttore = coppia.first;
        int mediaAltro = coppia.second;
        
        // non confrontare con se stesso
        if (altroProduttore == candidato){continue;}

        // se un mobile del candidato costa >= della media un altro produttore
        // allora non è economico

        if(prezzoCandidato >= mediaAltro){
          isEconomico = false;
          break;
        }
      }

      if (!isEconomico){break;}
    }

    // 4 se abbiamo trovato il primo produttore economico, conta i suoi mobiil
    if (isEconomico){return numeroProdotti[candidato];}

    // nessun produttore economico trovato 
    return -1;
  }

  
  int metodo3(){
    /////METODO 3
/*
Il metodo restituisce la differenza tra il numero di produttori che producono
 solo TAVOLI e il numero di pro
duttori che producono solo SEDIE.

Nel caso in cui non siano presenti mobili nel mobilificio, restituire -1.
*/

  }
  int metodo4(){
      
/////METODO 4
/*
Data la seguente definizione:
Un produttore P1 collabora con un produttore P2 se:
- P1 produce un mobile in collaborazione con P2, oppure
- P1 produce un mobile in collaborazione con P3 e P3 collabora con P2.

Inoltre ogni produttore collabora con se stesso.

Il metodo deve restituire il numero di produttori che collabora con l'ultimo 
produttore presente nella lista.

Nel caso in cui non ci siano mobili restituisce -1.

Esempio di collaborazione.

Supponiamo che:
- P1 realizza il mobile S con la collaborazione di P2.
- P2 realizza il mobile S1 con la collaborazione di P3.
- P3 realizza il mobile S2 con la collaborazione di P4.

P1 collabora con P1 (se' stesso), P2, con P3 e con P4.
P2 collabora con P2 (se' stesso), P3 e con P4.
P3 collabora con P3 (se' stesso), P4.
P4 collabora con P4 (se' stesso).

Se P1 fosse l'ultimo produttore della lista il metodo restituirebbe 4.
Se P4 fosse l'ultimo produttore della lista il metodo restituirebbe 1.
            
*/

    //caso base: nessun mobile
    if (mobili.empty()){
      return -1;
    }

    // 1. ottieni l'ultimo produttore della lista
    string ultimoProduttore = mobili.back().getProduttore();

    // 2. costruisci un grafo delle collaborazioni dirette
    // mappa: produttore -> set di produttori c on cui collabora direttamente

    map<string, set<string>> collaborazioni;

    // raccogli tutti i produttori e le loro collaborazionni dirette

    for (const Mobile& m : mobili){
      string prod = m.getProduttore();

      // ogni produttore collabora con se stesso
      collaborazioni[prod].insert(prod);

      // se il mobile ha collaboratori, aggiungili

      vector<string> collaboratori = m.getCollaboratore();
      for (const string& collab : collaboratori){
        collaborazioni[prod].insert(collab);

        // assicurati che anche il colaboratore sia nella mappa 
        if (collaborazioni.find(collab) == collaborazioni.end()){
          collaborazioni[collab].insert(collab);
        }
      }
    }

    // 3. calcola la chiusura transitiva per l'ultimo produttore 
    // usa BFS o DFS per trovare tutti i produttori raggiungibili

    set<string> raggiungibili;
    list<string> daVisitare;

    daVisitare.push_back(ultimoProduttore);
    raggiungibili.insert(ultimoProduttore);

    while (!daVisitare.empty()){
      string corrente = daVisitare.front();
      daVisitare.pop_front();

      // visita tutti i collaboratori diretti del produttore corrente

      if (collaborazioni.find(corrente) != collaborazioni.end()){
        for (const string& collab : collaborazioni[corrente]){
          // se non è stato ancora visitato, aggiungilo
          if (raggiungibili.find(collab) == raggiungibili.end()){
            raggiungibili.insert(collab);
            daVisitare.push_back(collab);
          }
        }
      }
    }

    // 4. restituisci il numero di produttori raggiungibili
    return raggiungibiil.size();

    // mannaia Michè perchè ti riduci a copiare il codice dall'AI, fai schifo

}
};
--------------------------







