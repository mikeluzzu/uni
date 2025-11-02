// scrivere una classe conto bancario che contiene il codice del conto e saldo, modificare il saldo e il conto
// (getter e setter), un metodo "preleva", "deposita", e "stampa"

//implementare l'operatore di assegnamento
// aggiungere a conto bancario operatori: uguale, lettura, stampa ==
#include <iostream>
#include <string>

using namespace std;

class ContoBancario {
    private:
        string titolareConto;
        string codiceConto;
        double saldo;
    public:
        // costruttore
        ContoBancario(string titolareConto = "", string codice = "", double saldoIniziale = 0.0) 
            : titolareConto(titolareConto), codiceConto(codice), saldo(saldoIniziale) {}

        // operatore di assegnamento
        ContoBancario& operator=(const ContoBancario& altro) {
            if (this != &altro) {  // controllo auto-assegnamento
                titolareConto = altro.titolareConto;
                codiceConto = altro.codiceConto;
                saldo = altro.saldo;
            }
            return *this;
        }

        // operatore di uguaglianza (==)
        bool operator==(const ContoBancario& altro) const {
            return (titolareConto == altro.titolareConto && 
                    codiceConto == altro.codiceConto && 
                    saldo == altro.saldo);
        }

        // operatore di disuguaglianza (!=)
        bool operator!=(const ContoBancario& altro) const {
            return !(*this == altro);
        }

        // operatore di output (<<) - dichiarato friend
        friend ostream& operator<<(ostream& os, const ContoBancario& conto) {
            os << "Titolare: " << conto.titolareConto 
               << ", Codice: " << conto.codiceConto 
               << ", Saldo: " << conto.saldo << " euro";
            return os;
        }

        // operatore di input (>>) - dichiarato friend
        friend istream& operator>>(istream& is, ContoBancario& conto) {
            cout << "Inserisci titolare del conto: ";
            //is.ignore(); // per pulire il buffer
            getline(is, conto.titolareConto);
            cout << "Inserisci codice conto: ";
            is >> conto.codiceConto;
            cout << "Inserisci saldo iniziale: ";
            is >> conto.saldo;
            return is;
        }

        // getter
        string getTitolareConto() const {
            return titolareConto;
        }

        string getCodiceConto() const {
            return codiceConto;
        }

        double getSaldo() const {
            return saldo;
        }

        // metodo getter stampa
        void infoConto() const {
            cout << "Titolare del conto: " << getTitolareConto() << endl;
            cout << "Codice conto: " << getCodiceConto() << endl; 
            cout << "Saldo: " << getSaldo() << " euro" << endl;
        }

        // metodo setter preleva
        bool preleva(double importo) {
            if (importo > 0 && importo <= saldo) {
                saldo -= importo;
                cout << "Prelevati " << importo << " euro con successo" << endl;
                return true;
            } else {
                cout << "Prelievo non riuscito: saldo insufficiente o input non valido." << endl;
                return false;
            }
        }

        // metodo setter deposita
        void deposita(double importo) {
            if (importo > 0) {
                saldo += importo;
                cout << "Deposito di " << importo << " euro effettuato con successo" << endl;
            } else {
                cout << "Importo non valido." << endl;
            }
        }
};

int main(){

    //test degli operatori
    cout << "=== Test operatori ===" << endl << endl;


    ContoBancario conto1("Scimmia Ubriaca, ", "0001", 1000.0);
    ContoBancario conto2;

    // test operatore di assegnamento
    cout << "Test operatore di assegnamento: " << endl;
    conto2 = conto1;
    cout << "Conto1: " << conto1 << endl;
    cout << "Conto2 (dopo l'assegnamento): " << conto2 << endl << endl;
    
    
    //test operatore di uguaglianza

    cout << "Test operatore di uguaglianza: " << endl;
    if (conto1 == conto2){
        cout << "I conti sono uguali" << endl;
    }else{
        cout << "I conti sono diversi" << endl;
    }

    cout << endl;

    // test operatore di input

    cout << "Test operatore di input: " << endl;
    ContoBancario conto3;
    cin >> conto3;
    cout << "Conto3 inserito: " << conto3 << endl << endl;

    
    // Test funzioni base

    cout << "Benvenuto nel tuo conto bancario." << endl;
    cout << "Scegli l'operazione da fare: 1.Vedi conto, 2. Preleva, 3.Deposita." << endl;
    int scelta;
    cout << "Inserisci: " << endl;
    cin >> scelta;

    switch(scelta){
        case 1:
            conto1.infoConto();
            break;
        case 2:
        {   
            cout << "Quanto vuoi prelevare?" << endl;
            double importo;
            cin >> importo;
            conto1.preleva(importo);
            cout << "saldo corrente: " << conto1.getSaldo() << " euro" << endl;
        
            break;
        }
            
        case 3:
            {   
            cout << "Quanto vuoi depositare?" << endl;
            double importo;
            cin >> importo;
            conto1.deposita(importo);
            cout << "saldo corrente: " << conto1.getSaldo() << " euro" << endl;
            break;
        }
        default:
            cout << "Scelta non valida." << endl;

    }
    return 0;
}
