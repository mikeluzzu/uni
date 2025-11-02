#include<iostream>
using namespace std;

class Punto{
   private:
      float x,y;
   public:
      Punto():x(0),y(0)
      {
      cout<<"COSTRUTTORE SENZA PARAMETRI di punto"<<endl;
      }
      Punto(float x1, float y1):x(x1), y(y1)
      {
      cout<<"COSTRUTTORE a 2 PARAMETRI di punto"<<endl;
      }
      
      float getX(){return x;}
      float getY(){return y;}
      void setX(float x1){ x=x1;}
      void setY(float y1){ y=y1;}
     
      friend istream& operator>>(istream&, Punto&);
      friend ostream& operator<<(ostream&, const Punto&);
};

//operatore di input
istream& operator>>( istream& i, Punto& p)
{
    i>>p.x>>p.y;
    return i;
    
}
//operatore di output
ostream& operator<<( ostream& o, const Punto& p)
{
    o<<"("<<p.x<<","<<p.y<<")";
    return o;
    
}

// classe cerchio che usa la composizione con Punto 
// (il centro del cerchio è un oggetto della classe punto)
class Cerchio
{
   private:
      float raggio;
      Punto centro;
   public:
      Cerchio()// questo costruttore chiamerà il costruttore senza parametri di Punto
      {
          cout<<"COSTRUTTORE SENZA PARAMETRI di cerchio"<<endl;
      }
      Cerchio(float r, float x, float y):raggio(r),centro(x,y) //centro(x,y) specifica che il centro deve essere costruito con il costruttore a 2 parametri di Punto
      {
          cout<<"COSTRUTTORE a 3 PARAMETRI di cerchio"<<endl;
      }
      
      Cerchio(float r, const Punto& c):raggio(r),centro(c)
      {
          cout<<"COSTRUTTORE a 2 PARAMETRI di cerchio"<<endl;
      }   

      float getRaggio(){return raggio;}
//operatore di input
friend istream& operator>>( istream& i, Cerchio& C)
{
    cout<<"inserisci le coordinate del centro e il raggio"<<endl;
    i>>C.centro>>C.raggio;
    return i;
    
}

//operatore di output
friend ostream& operator<<( ostream& o, const Cerchio& c)
{
    o<<c.centro<<" "<< c.raggio<<endl;
    return o;
    
}

const Cerchio& operator=(const Cerchio& c)
{
     if (&c !=this)
     {
        centro=c.centro; //chiamo operator= di punto
        raggio=c.raggio;
     }
     return *this;
}


};


int main()
{

Cerchio Array[3];
for(unsigned i=0; i<3; i++)
    cin>>Array[i];

unsigned posMax = 0;
for(unsigned i=1; i<3; i++)
    if (Array[i].getRaggio()>Array[posMax].getRaggio())
        posMax=i;
cout<<Array[posMax]; //serve definire operator<<



}
