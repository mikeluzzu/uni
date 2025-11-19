#include <iostream>
using namespace std;

class Base{
        public:
                int a = 3;
                void print(){cout << "base" << endl;}

};

class Derivata : public Base(){
        public:
                int b = 5;
                void print(){cout << "derivata" << endl;}
};


int main(){
    Base B;
    Derivata D;

    B.print();
    D.print();

    Base * pB = &B;

    (*pB).print();  //lo * per avere la precedenza sul punto dobbiamo metterlo tra parentesi
    pB->print();    // possiamo usare anche la freccia

    Derivata * pD = &D;

    (*pD).print();  //lo * per avere la precedenza sul punto dobbiamo metterlo tra parentesi
    pD->print();    // possiamo usare anche la freccia


    B=D; // questo funziona perchè sono numeri interi

    D=B; // questo 

    D=(Derivata)B; //cerco di forzare il cast sulla classe base

    pB = &D; // quindi qui prendo l'indirizzo della classe derivata e lo salvo in un puntatore della classe base
    pB->print(); // in questo caso punta ad un puntatore di classe Base e chiama il metodo di Base


    vector<Base> V;
    V.push_back(pB);
    

}

// 
