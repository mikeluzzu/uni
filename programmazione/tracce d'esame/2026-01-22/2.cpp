#include <iostream>
#include <map>
using namespace std;

class CalendarioRicevimenti{
private:
    map<string, int> ricevimenti;
public:    
    bool chiediRicevimento(const string studente, const string giorno, const int ora){
        if(!isLibero(giorno,ora)){return false}
        
        ricevimenti[giorno].push_back(ora);
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
};
