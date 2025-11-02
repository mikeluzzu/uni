#include<iostream>
using namespace std;

class VectorOfInt{
   int* array;
   unsigned  size; 
   unsigned capacity;
public:
   VectorOfInt():array(nullptr),capacity(0),size(0)
   {
     cout<<"costruttore senza parametri"<<endl;
   }
   VectorOfInt(unsigned c):array(new int[c]),capacity(c),size(0)
   { 
   cout<<"costruttore che riceve la capacity"<<endl;
   }
   // distruttore per deallocare la memoria allocata nel costruttore
   ~VectorOfInt(){
      cout<<"distruttore"<<endl;
      delete []array;
    }
   void push_back(int el)
   {
     if (size==capacity)
          if (capacity==0)
               resize(10);
          else  
               resize(capacity*2); 
     array[size++]=el; //array[size]=el; size+=1; 
   }
   
   void resize(unsigned C)
   {
     cout<<"chiamo resize passando da capacity "<<capacity <<" a capacity "<<C<<endl; 
     //supponiamo di gestire solo C>capacity
     if(C>=capacity)
     {
        int *temp=new int[C];
        for(unsigned i=0;i<size; i++)
           temp[i]=array[i];
        delete []array;
        array=temp;
        capacity=C;
     }
   }
   unsigned getSize() const {return size;}
   unsigned getCapacity() const {return capacity;}
   int& operator[] (unsigned i){cout<<"versione 1 "<<endl; return array[i];}
   int operator[] (unsigned i)const {cout<<"versione 2"<<endl; return array[i];}
   /* da implementare a casa 
   //costruttore per copia
   VectorOfInt(const VectorOfInt &C);
   //operatore di asseganamento
   operator= //da implementare;     
   */
};

void stampaMaggioriDi(const VectorOfInt &V, int x)
{
   cout<<"sono nella funzione stampa"<<endl;
   for(unsigned i=0; i<V.getSize(); i++)
       if (V[i]>x) //richiede di utilizzare la versione const di operator[]
           cout<<V[i];
}  

int main()
{
   VectorOfInt V;
   V.push_back(5);
   V.push_back(2);
   V[0]=3; //modifica il primo elemento del vector, richiede di utilizzare la versione non const di operator[] 
   for(unsigned i=0; i<V.getSize(); i++)
       cout<<V[i];
    cout<<endl; 
    stampaMaggioriDi(V,2);
   
    //provare che succede implementando operator= e senza implementarlo
    /*
    VectorOfInt V2;
    V2=V; 
    */
}
