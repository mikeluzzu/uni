/*
MASSIMO CON SCARTI

Leggere un array di dim elementi determinare il massimo e 
stampare l’elenco dei numeri contenuti nell’array ed il relativo 
scarto dal massimo.

*/
#include <iostream>
using namespace std;


int main()
{
 const unsigned int dim_max=10;
 int V[dim_max];
 //leggo l'array
 cout<<"Inserisci un array di "<< dim_max <<" elementi";
 for( int i=0;i< dim_max;i++){
     cin >> V[i];
 }
 
 //cerco il massimo
 int max=V[0];
 for (int i=1;i<dim_max;i++){
     if(V[i]>max)
        max=V[i];
 }
 cout<<"il massimo è:"<<max<<endl;
 
 //stampo i numeri nell'array e il relativo scarto da max
 for( int i=0;i< dim_max;i++){
     cout<<"elemento: "<< V[i]<<" scarto: "<<max-V[i]<<endl;
 }
 
 return 0; 
}
