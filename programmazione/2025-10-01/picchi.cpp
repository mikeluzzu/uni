#include <iostream>
using namespace std;

int main()
{int prec=0, corr=0, succ=0;
 int numPicchi=0, numDati=0;
 cin>>succ;
 while (succ!=-1)
 {numDati++;
  if (numDati>=3)
	if ((corr>prec) && (corr>succ))
	{ cout<<"Trovato picco: "<<corr<<" nel giorno "<<numDati-1<<endl;
	  numPicchi++;
	}
  prec=corr;
  corr=succ;
  cin>>succ;
 }
 cout<<"Numero di picchi massimi rilevati: "<<numPicchi<<endl;
 cout<<"Numero totale di dati: "<<numDati<<endl;
 return 0;

}
 

