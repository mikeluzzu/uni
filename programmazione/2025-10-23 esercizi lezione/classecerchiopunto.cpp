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
      
      Cerchio(float r, const Punto& c):raggio(r), centro(c)
      {
          cout<<"COSTRUTTORE a 2 PARAMETRI di cerchio"<<endl;
      }   

};


int main()
{

Punto P2(2,3);

Cerchio C(1,P2);

}
