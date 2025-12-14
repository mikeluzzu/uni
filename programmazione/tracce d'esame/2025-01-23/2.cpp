#include<iostream>
#include<string>
#include<list>
#include<queue>
#include<set>

using namespace std;

class WebPage{
private:
	string titolo;
	string testo;
	list<WebPage*> links; //lista di puntatori ad altre WebPage

public:
	WebPage() = default;

	//costruttore con parametri
	WebPage(const string& t, const string& txt) :
	titolo(t), testo(txt) {}

	string getTitolo() const {return titolo;}
	string getTesto() const {return testo;}

	// getter per i links, const per evitare modifiche
	const list<WebPage*>&  getLinks() const {return links;}

	void aggiungiLink(WebPage* link){
		links.push_back(link);
	}

	bool operator == (const WebPage& other) const {
		return titolo == other.titolo;
	}
};

class WebSite {
private:
	WebPage* homepage; // pagina di accesso al sito

public:
	WebSite(WebPage* home) : homepage(home){}

	//trova la distanza minima della homepage a target
	// usa la BFS (Breadth First Search), visita in ampiezza

	int find_webpage(const WebPage& target) const {
		if(homepage == nullptr) return -1;

		// se la homepage e' il target, distanza = 0
		if(*homepage == target) return 0;

		// coda per BFS: coppia(pagina corrente, distanza dalla homepage)
		queue<pair<WebPage*,int>> q;
		q.push({homepage, 0});

		// set per tracciare le pagine visitate (evita cicli infiniti)
		set<WebPage*> visitati;
		visitati.insert(homepage);

		//BFS

		while(!q.empty()){
			WebPage* corrente = q.front().first;
			int distanza = q.front().second;
			q.pop();

			// esplora tutti i link della pagina corrente
			for(WebPage* vicino : corrente->getLinks()){
				// se non ancora visitato
				if (visitati.find(vicino) == visitati.end()){
					// se e' il target, abbiamo trovato
					if(*vicino == target){
						return distanza + 1;
					}
					
					// altrimenti aggiungi alla coda e marca come visitato
					visitati.insert(vicino);
					q.push({vicino, distanza + 1});
				}
			}
		}
		// se arriviamo qui, il target non e' trovato
		return -1;
	}
};


// Esempio d'uso
int main() {
    // Creazione pagine
    WebPage home("Home", "Benvenuti nel sito");
    WebPage about("About", "Chi siamo");
    WebPage contacts("Contatti", "Scrivici");
    WebPage blog("Blog", "Articoli recenti");
    
    // Struttura del sito:
    // Home -> About -> Contacts
    //      -> Blog
    home.aggiungiLink(&about);
    home.aggiungiLink(&blog);
    about.aggiungiLink(&contacts);
    
    // Creazione sito
    WebSite sito(&home);
    
    // Test
    cout << "Distanza da home a About: " << sito.find_webpage(about) << endl;      // 1
    cout << "Distanza da home a Contacts: " << sito.find_webpage(contacts) << endl; // 2
    cout << "Distanza da home a Blog: " << sito.find_webpage(blog) << endl;        // 1
    
    WebPage esterna("Esterna", "Non nel sito");
    cout << "Distanza da home a Esterna: " << sito.find_webpage(esterna) << endl;  // -1
    
    return 0;
}