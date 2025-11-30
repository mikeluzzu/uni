#include <iostream>
using namespace std;

int main()
{int V[100], dim=0, i, indice, trovato=0, num, card_max=0, card_ins=0;
 cin>>num;
 while (num!=-1)
 {V[dim]=num;
  dim++;
  cin>>num;
 }

 cin>>card_max; //non e' strettamente necessario leggere card_max,
		//andava supposto dato.
 i=0;
 while ((i<dim)&&(!trovato))
 {if (V[i]!=0)
    card_ins++;
  else
  { if (card_ins==card_max)
       {trovato=1;
	indice=i;
       }
    card_ins=0;
  }
  i++;
 }

 cout<<"L'insieme con la massima cardinalita' e': "<<endl;
 for (i=indice-card_max; i<indice;i++)
  cout<<V[i]<<endl;

 return 0;

}

