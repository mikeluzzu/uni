
#include<iostream>
using namespace std;

int main()
{
   unsigned int n;
   cout<<"inserisci numero intero positivo"<<endl;
   cin>>n; //10

   unsigned somma=0;
   for( unsigned x=1; somma<n; ++x)
   {
      somma+=x;
   }

   if (somma==n)
     cout<<"SI"<<endl;
   else
     cout<<"NO"<<endl;

}

