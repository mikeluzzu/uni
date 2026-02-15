#include<vector>
#include<string>
using namespace std;

class GestioneDebiti{
private:
    vector<string> amici;
    vector<vector<float>> debiti;

    int trovaIndice(const string& nome)const {
        for(int i = 0; i < amici.size(); i++)
            if(amici[i] == nome) return i;
        return -1;
    }

public:
    GestioneDebiti(vector<string>& amici) : amici(amici){
        int n = amici.size();
        debiti.resize(n, vector<float>(n, 0.0));
    }

    void anticipa(string x, string y, float k){
        int ix = trovaIndice(x);

        if (y == "*"){
            int n = amici.size();
            float quota = k / n;

            for(int i = 0; i < n; i++)
                if (i != ix)
                    debiti[i][ix] += quota;
            
        }else{
            int iy = trovaIndice(y);
            debiti[iy][ix] += k;
        }
    }


    float saldo(string x, string y) const {
        int ix = trovaIndice(x);
        int iy = trovaIndice(y);

        float saldoNetto = debiti[ix][iy] - debiti[iy][ix];
        return max(0.0f, saldoNetto);
    }


    void paga(string x, string y, float k){
        int ix = trovaIndice(x);
        int iy = trovaIndice(y);

        float saldoAttuale = saldo(x,y);

        if (saldoAttuale > 0 && k <= saldoAttuale)
            debiti[ix][iy] -= k;
    }
};