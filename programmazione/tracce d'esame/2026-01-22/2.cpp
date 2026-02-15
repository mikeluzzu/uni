#include <iostream>
#include <map>
using namespace std;

class CalendarioRicevimenti{
private:
    map<string, vector<pair<int, string>>> ricevimenti;
public:    
    bool chiediRicevimento(const string studente, const string giorno, const int ora){
        if(!isLibero(giorno,ora)){return false}
        
        ricevimenti[giorno].push_back(make_pair(ora, studente));
        return true;
    }

    void libera(string& giorno){
        ricevimenti.erase(giorno);
    }

    bool isLibero(const string& giorno, const int ora){
        if (ora < 8 || ora > 19) {return false;}

        for (int oraOccupata : ricevimenti[giorno]){
            if (oraOccupata == ora){return false;}
        }
        return true;
    }

    bool operator==(const CalendarioRicevimenti& altro) const{
        return ricevimenti == altro.ricevimenti;
    }

    vector<string> operator[](const string& giorno){
        vector<string> studenti;
        if(ricevimenti.find(giorno) == ricevimenti.end()){
            return studenti;
        }
        
        for(int i = 0; i < ricevimenti[giorno].size(); i++){
            studenti.push_back(ricevimenti[giorno][i].second)
        }
        return studenti;
    }
};
