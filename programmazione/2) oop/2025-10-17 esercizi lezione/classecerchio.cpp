
#include<iostream>
using namespace std;

class Cerchio
{
private:
    float x,y;
    float raggio;
public:
    /* versione con 4 costruttori
    Cerchio(){}
    Cerchio(float r): raggio(r),x(0),y(0)
    {}
    Cerchio(float x1,float y1): raggio(0),x(x1),y(y1)
    {}
    Cerchio(float r, float x1, float y1):raggio(r), x(x1), y(y1)
    {}
    */
     //versione con 1 costruttore e valori di default
    Cerchio(float r=0, float x1=0, float y1=0):raggio(r),x(x1),y(y1)
    {}
    Cerchio(const Cerchio& c): raggio(c.raggio),x(c.x),y(c.y)
     
    {cout<<"sono nel costruttore per copia"<<endl;}    
    float getRaggio() const //metodo getter
    {
        return raggio;
    }    
    float getX() const//metodo getter
    {
        return x;
    }    
    float getY() const//metodo getter
    {
        return y;
    }    
    void setRaggio(float h)
    {
        if (h<0)
        {
             cout<<"nuovo valore negativo, modifica non apportata";
             return;
        }
        raggio = h;
    }
    void stampa() const
    {
      cout<<" cerchio di raggio "<<raggio <<" e centro in " <<"("<<x<<","<<y<<")"<<endl;
    }
    ~Cerchio(){cout<<"sono il distruttore del cerchio di raggio "<<raggio<<endl;}

};

float calcolaArea(const Cerchio &c)
{
    return c.getRaggio()*c.getRaggio()*3.14;
}

int main()
{
   Cerchio C(3);  // invocazione del metodo costruttre

   cout<<calcolaArea(C);
   Cerchio * T=new Cerchio(4); // creazione di un cerchio dinamico
   delete T; 
   
}
