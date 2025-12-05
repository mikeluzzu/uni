/*
sort(), find()

classe algorithm, documentazione su cplusplus.com

per utilizzare sort serve l'operatore "<" 




*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Prodotto{
    private:
            unsigned int id;   
            string nome;
    
    public:
            Prodotto(unsigned int id, string nome): id(id), nome(nome){}

    friend ostream& operator << (ostream& o, const Prodotto& p){
        o << "id: " << p.id << " nome: " << p.nome << endl;
        return o; 
    }

    bool operator < (const Prodotto & p2) const {
        return nome < p2.nome;
    }
    string getNome() const {return nome;}

    unsigned int getId(){return id;}
};

bool cmp(const Prodotto & p1, const Prodotto  & p2){
    return pl.getId() < p2.getId();
}

int main(){
    Prodotto p1(10, "Sale");
    Prodotto p2(1, "Pepe");
    Prodotto p3(2, "Arancia");
    vector<Prodotto> v = {p1,p2,p3};

    for(Prodotto p : v )
        cout << p;

    sort(v.begin() , v.end());
    cout << "vettore ordinato con sort" << endl;

    for (Prodotto p : v)
        cout << p;

    return 0;
}