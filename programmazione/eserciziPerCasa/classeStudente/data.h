#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Data {
private:
    int giorno;
    int mese;
    int anno;
    
    // Metodo privato per validare la data
    bool isValida() const;
    
public:
    // Costruttori
    Data();
    Data(int g, int m, int a);
    
    // Metodi set
    void setGiorno(int g);
    void setMese(int m);
    void setAnno(int a);
    void setData(int g, int m, int a);
    
    // Metodi get
    int getGiorno() const;
    int getMese() const;
    int getAnno() const;
    
    // Metodi I/O
    void leggi();
    void stampa() const;
};

#endif