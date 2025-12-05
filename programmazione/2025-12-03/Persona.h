#include <string>
using namespace std;
class Persona{
    private:
            string nome;
            string cognome;
    public:
            string getNome(){return nome;}
            string getCognome() {return cognome;}
            
            void setNome(string & n){nome = n;}
            void setCognome(string & c){cognome = c;}

            Persona(string n = "", string c = ""): nome(n), cognome(c){}

            friend ostream& operator << (ostream& os, const Persona& p);

            friend istream& operator >> (ostream& is, const Persona & p);

}

// implementazione fuori dalla classe del friend operator

ostream& operator << (ostream & os, const Persona& p){
    os << "Nome: " << p.nome << ", Cognome: " << p.cognome << ", Età: " << p.eta;
    return os;
}

istream& operator << (istream & is, const Persona& p){
    cout << "Inserisci nome: ";
    is >> p.nome;
    cout << "Inserisci cognome: ";
    is >> p.cognome;
    return is;
}
