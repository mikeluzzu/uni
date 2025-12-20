 // per pognuna delle istruzioni presenti  dire se è corretta o no e specificare perche'

#include<iostream>
using namespace std;
class A{
   public:
     int i1; 
   protected:
     int i2;
   private:
      int i3;

};


class D1: private A
{
  public:

   void f()
     {
     i1=0;
     i2=0;
     i3=0;
     }
};
class D2: protected A
{
  public:

   void g()
     {
     i1=0;
     i2=0;
     i3=0;
     }
};
class D3: public A
{
  public:

   void h()
     {
     i1=0;
     i2=0;
     i3=0;
     }
};

class D2A:public D2
{
   public:
   using D2::i1;
   using D2::i3; 
   void ga()
   {
      i1=0;
      i2=0;
      i3=0; 
   }
};
int main()
{
   A a;
   a.i1=0;
   a.i2=0; 
   a.i3=0; 
  D1 d;
    d.i1=0; 
    d.i2=0; 
    d.i3=0; 
  D2 d2;
    d2.i1=0; 
    d2.i2=0; 
    d2.i3=0; 
  D3 d3;
  d3.i1=0; 
  d3.i2=0; 
  d3.i3=0;   
  D2A d2a;
  d2a.i1=0;
  d2a.i2=0;
  d2a.i3=0;
}
