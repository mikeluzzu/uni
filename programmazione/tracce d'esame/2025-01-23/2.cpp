#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Webpage {
    private:
        const string titolo; 
        const string testo;
        vector<Webpage*> link; 

    public:
        Webpage(): link({}) {}
        
        Webpage(const string& ti, const string& te, const vector<Webpage*>& l) 
        : titolo(ti), testo(te), link(l) {}

        string getTitolo() const {return titolo;}
        string getTesto() const {return testo;}
        const vector<Webpage*>& getLink() const {return link;}

        void aggiungiLink(Webpage* w) {link.push_back(w);}

        bool operator==(const Webpage& other) {
            return titolo==other.titolo;  
        }
};

class Website {
    private:    
        Webpage homepage; 
    public:
        Website() = default; 
        Website(Webpage h): homepage(h) {}

        int find_webpage(const Webpage& target) const {
            queue<Webpage> daVisitare;
            daVisitare.push(homepage);

            vector<Webpage> visitate;
            visitate.push_back(homepage);

            int level = 0;  // contatore dei livelli
            while (!daVisitare.empty()) {
                int levelSize = daVisitare.size();  // numero di nodi in questo livello
                // processa tutti i nodi del livello corrente
                for (int i = 0; i < levelSize; i++) {
                    Webpage curr_page = daVisitare.front(); // prendo in lettura la pagina corrente e la estraggo con pop()
                    daVisitare.pop();
                    // se ho trovato target, ritorno il livello
                    if (curr_page == target)
                        return level;       
                    for (Webpage* w : curr_page.getLink()) {
                        if (find(visitate.begin(), visitate.end(), *w) == visitate.end()) {
                            visitate.push_back(*w);
                            daVisitare.push(*w);
                        }
                    }
                }
                level++;  // incrementa il livello dopo aver processato tutti i nodi del livello
            }
            return -1;
        }
};

