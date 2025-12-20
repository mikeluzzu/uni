#include<iostream>
 const int righe=3;
 const int colonne=3;

using namespace std;
void stampaRicorsiva(int **,int,int,int);
void stampaARRAYRicorsiva(int a[],int,int);

int main()
{
  int a[10]={0};
  stampaARRAYRicorsiva(a,10,0); 
   
  int **mat=new int*[righe];
  for(unsigned i=0;i<righe;i++)
    mat[i]=new int[colonne];  
  
  stampaRicorsiva(mat,righe, colonne,0);
 
  
}


void stampaARRAYRicorsiva(int a[], int dim,int i)
{
   if (i==dim)
   {
      cout<<endl;
      return;
   } 
   cout<<a[i]<<" ";
   stampaARRAYRicorsiva(a,dim,i+1);
} 
     


void stampaRicorsiva(int **M,int r,int c, int riga)
{
   if(riga==r)
     return;
   stampaARRAYRicorsiva(M[riga],c,0);
   stampaRicorsiva(M,r,c,riga+1);
}

