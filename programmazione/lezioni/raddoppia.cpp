#include <iostream>
using namespace std;
void raddoppia(int * &, int &);
void incrementa(int [], int);
void stampa(int [], int);


int main(){
	int dim=10, x, i=0;
	int *a= new int [dim];
	cin >> x;

	while(x!=0){
		if(i==dim){
			raddoppia(a,dim);		
		}
		a[i++] = x;
		cin >>x;
	}
	
	int a[5]={1,2,3,4,5};
	incrementa(a,dim)   
}

void raddoppia(int * &a, int &dim){
	int *temp = new int [dim]
}

void incrementa(){
	
}
