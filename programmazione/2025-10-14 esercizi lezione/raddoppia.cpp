#include<iostream>
using namespace std;

void raddoppia(int* &, int&);
void incrementa(int *, int);
void stampa(int [], int);

int main()
{
   int dim=10,x,i=0;
   int * a=new int[dim];
   cin>> x;
   while(x!=0)
   {
      if(i==dim)
          raddoppia(a,dim);
      
      a[i++]=x;
      cin>>x;
  
   } 
   int b[5]={1,2,3,4,5};
   incrementa(b,5);
   stampa(b,5);

}

void raddoppia(int * &a, int& dim)
{
    int *temp=new int[dim*2];
    for(unsigned i=0; i<dim; i++)
       temp[i]=a[i];
    delete []a;
    a=temp;
    dim*=2;
}

void incrementa(int *a, int n)
{
   for(unsigned i=0; i<n; i++)
      a[i]++;
}
void stampa(int a[], int n)
{
   for(unsigned i=0; i<n; i++)
      cout<<a[i];
}
