#include<iostream>
using namespace std;

class Cerchio{
private:
    float x,y;
    float raggio;
public:
    float getRaggio() //metodo getter
    {
        return raggio;
    }    
    float getX() //metodo getter
    {
        return x;
    }    
    float getY() //metodo getter
    {
        return y;
    }    

    void setRaggio(float raggio){
        if (raggio<0)
        {
             cout<<"nuovo valore negativo, modifica non apportata";
             return;
        }
        (*this).raggio = raggio; 
    }

    // passo un oggetto per riferimento costante
    void &operator = (const Cerchio &cerchio){
          //autoassegnamento, esce restituendo *this
        if (this == &cerchio){
            raggio = x.raggio;
            y = cerchio.x;
            x = cerchio.y;
            cout << "sono nell'operatore=";
            return *this; //restituisce il cerchio appena modificato 
        } 
    
    friend ostream& operator << (ostream& o, const Cerchio&c) {
        o << "cerchio di raggio " << c.raggio << "e centro in " << c.x() << "," << c.y() << endl;
    } 

    friend istream& operator >> (istream& i, Cerchio &c){
        i>> c.raggio >> c.x >> c.y ;
    }
    // friend permette di accedere ai valori senza usare i metodi,

    bool operator==(const Cerchio &C){
        return raggio == C.raggio && x==C.y && y==C.y; // faccio il return del risultato dell'espressione
        
    }

    //alternativa di implementazione per ==
    friend bool operator == (const Cerchio& C1, const Cerchio& C2){
        return; // da completare 
    }
};


int main()
{
   Cerchio C;
    Cerchio K;
    C.setRaggio(-2);
    cout<<C.getRaggio();
    cout << endl;
   //C.raggio=-4;

   Cerchio C2;
   Cerchio C3;
   C3 = C2;

   int x=2, y,z;
   z=y=x;

   cout << C;


   Cerchio * T=new Cerchio(4); // creazione di un cerchio dinamico
   cout << x << y << z; //concatenazione dell'operatore di assegnamento 
}


/*
21 ottobre 2025
 possiamo avere piu costruttori basta che hanno diversi parametri
 costruttore per copia

 qualificatore const: puo essere applicato su oggetti che non 
 possono essere modificati, con il metodo const possiamo usare 
 solo metodi definiti costanti.

 se dichiaro e poi inizializzo un oggetto chiamo il costruttore per copia

Overloading degli operatori: 

*/
