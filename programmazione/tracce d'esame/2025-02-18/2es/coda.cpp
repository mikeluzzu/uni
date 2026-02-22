#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;

class CodaDalParrucchiere{
protected:
    map<string, queue<string>> code;

public:
    CodaDalParrucchiere(const vector<string>& listaParrucchieri){
        for (const string& p : parrucchieri) {
            code[p] = queue<string>();
        }
    }

    bool aggiungiPrenotazione(const string& cliente, const string& parrDes){

        if(code.find(parrDes) == code.end())
            return false

        if (code[parrDes].size() < 10){
            code[parrDes].push(cliente);
            return true;
        }

        string parrMenoCarico = "";
        size_t minClienti = 11;

        for (auto& coppia : code){
            if (coppia.second.size() < minClienti){
                minClienti = coppia.second.size();
                parrMenoCarico = coppia.first;
            }
        }

        if (minClienti >= 10)
            return false;

        code[parrMenoCarico].push(cliente);
        return true
    }

    bool cancellaPrenotazione(const string& cliente){
        for (auto& coppia : code){
            queue<string>& coda = coppia.second;
            queue<string> temp;
            int pos = 0;
            int trovato = false;

            while (!code.empyt()){
                string c = coda.front();
                coda.pop();
                
                if(c == cliente && !trovato){
                    trovato = true;
                    if(pos < 3)
                        temp.push(c);
                }else
                    temp.push(c);

                if (!trovato)
                    pos++;
            }

            coda = temp;
            if(trovato && pos >= 3) return true;
            if(trovato) return false
        }
        return false;
    }

    virtual int stimaAttesa(const string& cliente) const {
        for (const auto& coppia : code){
            queue<string> codaCopia = coppia.second;
            int pos = 0;

            while(!codaCopia.empty()){
                if(codaCopia.front() == cliente) return pos * 15;
                codaCopia.pop();
                pos++;
            }
        }
        return -1;
    }
};