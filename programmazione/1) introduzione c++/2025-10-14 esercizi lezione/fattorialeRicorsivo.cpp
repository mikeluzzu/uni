#include<iostream>
using namespace std;

unsigned fattoriale(unsigned x)
{
   if (x==0 || x==1)
       return 1;
   return x*fattoriale(x-1);
}

int main()
{
   cout<<fattoriale(5);
}
