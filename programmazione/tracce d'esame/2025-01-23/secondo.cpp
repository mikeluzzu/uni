#include<string>
#include<vector>
#include<queue>
using namespace std;

class Webpage{
private:
    const string titolo;
    const string testo;
    vector<Webpage*> link;

public:
    WebPage(const string& ti, const string& te, const vector<Webpage*>& l) :
    titolo(ti), testo(te), link(l){}

    string getTitolo() const {return titolo;}
    string getTesto() const {return testo;}
    vector<Webpage*>& getLink() const {return link;}

    void addLink(vector<WebPage*>& link, const string& l ){
        link.push_back(l);
    }

    bool operator==(const Webpage& other){
        return titolo == other.titolo; 
    }
};

class Website {
private:
    string homepage;
public:
    Website(string h) : homepage(h){}

    int find_webpage(const WebPage& target){
        queue<Webpage> daVisitare;
        daVisitare.push(homepage)

        vector<Webpage> visitate;
        visitate.push_back(homepage);

        int level;
        while(!daVisitare.empty()){
            int levelSize = daVisitare.size();
            for(int i = 0; i < levelSize; i++){
                Webpage curr = daVisitare.front();
                daVisitare.pop();
                if (curr == target) 
                    return level;

                for(Webpage* : curr.getLink()){
                    if (find(visitate.begin(), visitate.end(), w*) == visitate.end()){
                        visitate.push_back(w*);
                        daVisitare.push(w*);
                    }
                }

            }
            level ++;
        }
        return -1;
    }
};