
#include<iostream>
using namespace std;



class Cerchio
{
private:
    float x,y;
    float raggio;
public:
    // versione con 4 costruttori
    Cerchio(){    
        cout<<"sono nel costruttore 0"<<endl;
    }
    Cerchio(float r): raggio(r),x(0),y(0)
    {    
        cout<<"sono nel costruttore 1"<<endl;
    }
    Cerchio(float x1,float y1): raggio(0),x(x1),y(y1)
    {    
        cout<<"sono nel costruttore 2"<<endl;
    }
    Cerchio(float r, float x1, float y1):raggio(r), x(x1), y(y1)
    {    
        cout<<"sono nel costruttore 3"<<endl;
    }
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
    
    void setRaggio(float);
    void setX(float x1)
    {
    x=x1;
    }
    void setY(float y1)
    {
    y=y1;
    }
    ~Cerchio()
    {
        cout<<"sono il distruttore del cerchio di raggio "<<raggio<<endl;
    }
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

   // implementazione di < come metodo della classe
   bool operator<(const Cerchio& C) const
   {
       return raggio<C.raggio;
   }  
   // implementazione di == come funzione esterna friend della classe
   friend bool operator==(const Cerchio& C1, const Cerchio & C2)
   {
       return C1.raggio==C2.raggio && C1.x==C2.x && C1.y==C2.y;
   }

   friend bool operator<=(const Cerchio& C1,const Cerchio& C2)
   {
       return C1.raggio<=C2.raggio;
   } 

   const Cerchio& operator+=(const Cerchio& C) 
   { 
       raggio+=C.raggio;
       return *this; 
   }

   Cerchio operator+(const Cerchio& C) const
   {  
       Cerchio NC(raggio+C.raggio);
       return NC;
   }  

   friend Cerchio operator-(const Cerchio& C1, const Cerchio &C2)
   {  
       return Cerchio(C1.raggio-C2.raggio);
   }
};

// esempio di implementazione di un metodo fuori dalla classe
void Cerchio::setRaggio(float raggio)
    {
        if (raggio<0)
        {
             cout<<"nuovo valore negativo, modifica non apportata";
             return;
        }
        this->raggio = raggio; //risolve l'ambiguità di nome con il parametro passato
    }


int main()
{
   Cerchio C(3);  

   Cerchio C2(1,1,1);

   Cerchio K;
   cin>>K;
   if (K==C2) //equivale a if( operator==(K,C2) ) 
      cout<<"sono cerchi uguali"<<endl;
   
   else if (K<C2) //equivale a if( K.operator<(C2) )
       cout<<"il primo e' minore"<<endl;
  
   //sto invocando += e su K modificato invoco getX()
   cout<<(K+=C2).getX()<<endl;
   cout<<"dopo += il cerchio sara'"<<K<<endl;    
   
   Cerchio NC=C+C2;
   cout<<NC;
   Cerchio MC=C-C2;
   cout<<MC;
   

   cout<<"sta terminando il main "<<endl; 
}
