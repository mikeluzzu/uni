#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Prodotto{
    private:
    int id;
    string nome;
    public:
    
    
    Prodotto(int id, string nome):id(id),nome(nome){}
    
    bool operator<(const Prodotto& p2){
        return nome<p2.nome;
    }
    bool operator==(const Prodotto& p2){
        return nome==p2.nome&&id==p2.id;
    }

    // operatore di stampa
    friend ostream & operator<<(ostream & o, const Prodotto & p){
        o << p.id << " " << p.nome;
        return o;
    }

    int getId(){return id;}
    string getNome()const{return nome;}
    
};

bool mycmp(const Prodotto& p1, const Prodotto& p2){return p1.getNome() < p2.getNome();}

int main()
{
    Prodotto p1(1,"Sugo");
    Prodotto p2(2,"Pesto");
    Prodotto p3(3,"Amatriciana");
    Prodotto p4(4, "Lasagna");

    vector<Prodotto> v = {p1,p2,p3,p4};
    
    for(Prodotto p : v){
        cout << p << endl;
    }

    sort(v.begin(),v.end(),mycmp);

    cout << endl;

    for(Prodotto p:v){
        cout << p << endl;
    }

    cout << endl;

    cout << "Find di un prodotto:" << endl;
    vector<Prodotto>::iterator it = find(v.begin(), v.end(), p1);
    if(it != v.end())
        cout << *(it);
    else
        cout << "not found";

    cout << endl;
    return 0;
}
