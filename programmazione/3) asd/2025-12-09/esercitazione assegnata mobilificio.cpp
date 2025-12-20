#include<string>
#include<iostream>
using namespace std;
/*
  Questa classe contiene una lista di mobili. Ogni mobile e` caratterizzato dalle seguenti informazioni:

    - nomeMobile: il nome di un mobile (string);

    - produttore: il nome del produttore che ha prodotto il mobile (string);

    - prezzo: il prezzo del mobile (int);

    - tipo: il tipo del mobile (un enumerativo con 5 possibili valori: TAVOLO, SEDIA, COMODINO, ARMADIO;

    - collaboratore: il produttore che ha collaboratore nella realizzazione del mobile, stringa vuota se non
 esiste un collaboratore (string).

    Implementare nel file Mobilificio.cpp i metodi della classe Mobilificio.
*/
enum Tipo { TAVOLO = 0, SEDIA, COMODINO, ARMADIO };

class Mobile
{
private:
   string nomeMobile;
   string Produttore;
   int Prezzo;
   Tipo tipo;
   string Collaboratore;
public:
   Mobile(const string &m="", const string &p="", int pr=0, Tipo t=TAVOLO, const string &c=""):
    nomeMobile(m), Produttore(p), Prezzo(pr), tipo(t), Collaboratore(c) {} 
   string getNome() const {return nomeMobile;}
   string getProduttore() const {return Produttore;}
   int getPrezzo() const {return Prezzo;}
   Tipo getTipo() const {return tipo;}
   string getCollaboratore() const {return Collaboratore;}
};
------------------------------
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
  int metodo1();
  int metodo2();
  int metodo3();
  int metodo4();
};
--------------------------

/////METODO 1
// Sia X la media dei prezzi di tutti i mobili. Determinare il massimo
// prezzo fra quelli che hanno un prezzo minore o uguale a X.

// Per il calcolo della media utilizzare la divisione intera.

// Se non sono presenti mobili, restituire -1.


/////METODO 2
/*Per ogni produttore P sia M(P) il prezzo medio dei mobili prodotti da P.
Un produttore si dice economico se produce solo mobili che costano meno
del prezzo medio M(P) di ogni *altro* produttore.
Attenzione: Il prezzo dei prodotti del produttore economico E non e' mai confrontato
            con la media M(E) (cioe' e' confrontato con tutti tranne che con se stesso).

Il metodo restituisce il numero di mobili prodotti dal *primo* produttore economico della lista.

Per il calcolo della media utilizzare la divisione intera.

Se non sono presenti mobili oppure se nessun produttore verifica la condizione oppure se c'e' un solo produttore, restituire -1.
*/

/////METODO 3
/*
Il metodo restituisce la differenza tra il numero di produttori che producono solo TAVOLI e il numero di pro
duttori che producono solo SEDIE.

Nel caso in cui non siano presenti mobili nel mobilificio, restituire -1.
*/

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
