
#include<iostream>
using namespace std;



class Cerchio
{
private:
    float x,y;
    float raggio;
public:
    // versione con 4 costruttori
    Cerchio(){    cout<<"sono nel costruttore 0"<<endl;
}
    Cerchio(float r): raggio(r),x(0),y(0)
    {    cout<<"sono nel costruttore 1"<<endl;
}
    Cerchio(float x1,float y1): raggio(0),x(x1),y(y1)
    {    cout<<"sono nel costruttore 2"<<endl;
}
    Cerchio(float r, float x1, float y1):raggio(r), x(x1), y(y1)
    {    cout<<"sono nel costruttore 3"<<endl;
}
    
     //versione con 1 costruttore e valori di default
  /*  Cerchio(float r=0, float x1=0, float y1=0):raggio(r),x(x1),y(y1)
    { 
  }*/
    Cerchio(const Cerchio& c): raggio(c.raggio),x(c.x),y(c.y)
     
    {
    cout<<"sono nel costruttore per copia"<<endl;
    }    
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
    void setRaggio(float raggio)
    {
        if (raggio<0)
        {
             cout<<"nuovo valore negativo, modifica non apportata";
             return;
        }
        this->raggio = raggio; //risolve l'ambiguità di nome con il parametro passato
    }
    void stampa() const
    {
      cout<<" cerchio di raggio "<<raggio <<" e centro in " <<"("<<x<<","<<y<<")"<<endl;
    }

    ~Cerchio(){cout<<"sono il distruttore del cerchio di raggio "<<raggio<<endl;}
   
   const Cerchio& operator=( const Cerchio& cerchio)
   {
       if (this != &cerchio) //si tratta di autoassegnamento, esci restituendo  *this
       {       
          raggio=cerchio.raggio;
          x=cerchio.x;
          y=cerchio.y;
       }
       cout<<"sono nell'operatore="<<endl;
       return *this; 
   } 
friend ostream& operator<<(ostream& o, const Cerchio &c)
{
      o<<" cerchio di raggio "<<c.raggio <<" e centro in " <<"("<<c.x<<","<<c.y<<")";     
      return o;
}
friend istream& operator>>(istream& i, Cerchio &c)
{
      i>>c.raggio>>c.x>>c.y;     
      return i;
}

/*
//Possibile implementazione per ==
bool operator==(const Cerchio &C)
{
     return raggio==C.raggio && x==C.x && y==C.y;
}*/

//alternativa di implementazione per ==
friend bool operator==(const Cerchio& C1, const Cerchio & C2)
{
     return C1.raggio==C2.raggio && C1.x==C2.x && C1.y==C2.y;

}
  
};


float calcolaArea(const Cerchio &c)
{
    return c.getRaggio()*c.getRaggio()*3.14;
}

int main()
{
   Cerchio C(3);  // invocazione del metodo costruttre

   Cerchio C2(1,1,1);
    Cerchio C3;
    C3=C2;
   int x=2, y,z;
   
   z=y=x;
   cout<<x<<y<<z<<endl;
   cout<<calcolaArea(C);

   Cerchio K;
   cin>>K;
   cout<<"stampo un "<<K<<endl;
   if (K==C2) //if (K.operator==(C2)) oppure if( operator==(K,C2) )
      cout<<"sono cerchi uguali"<<endl;
   

   Cerchio * T=new Cerchio(4); // creazione di un cerchio dinamico
   delete T; 
   
}
