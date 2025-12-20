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
           nomeMobile(m), Produttore(p), Prezzo(pr), tipo(t), Collaboratore(c)
   {} 
   string getNome() const {return nomeMobile;}
   string getProduttore() const {return Produttore;}
   int getPrezzo() const {return Prezzo;}
   Tipo getTipo() const {return tipo;}
   string getCollaboratore() const {return Collaboratore;}
};