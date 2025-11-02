/*Modellare e implementare una classe Webpage che modelli una pagina web. Ciò che ci interessa 
memorizzare è il titolo della pagina, il testo contenuto in essa e l’insieme dei suoi link
(collegamenti ad altre Webpage). Si richiede inoltre di poter leggere queste informazioni 
dall’esterno della classe, da cui si deve anche poter aggiungere nuovi link ma senza la possibilità 
di rimuoverli, mentre il testo e il titolo della pagina, una volta creata, devono essere 
immutabili. Infine, si richiede di definire un operatore di confronto tra due Webpage, ritenute 
uguali se hanno lo stesso titolo.
Si richiede poi di implementare una classe Website che modelli la struttura di un sito web. Un 
Website è sostanzialmente un insieme di Webpage collegate tra loro e da cui si accede tramite 
una Webpage specifica detta homepage. All’interno di Website si richiede di implementare un metodo 
int find_webpage(const Webpage& target) const { … }
il quale, presa in input una Webpage, restituisce il minimo numero di link da attraversare per 
trovare la pagina target e -1 se target non appartiene al sito.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WebSite{
	private:
		vector<string> sito; 
		string homePage;
		
};

class WebPage{
	private:
		string titoloPagina;
		string testoPagina;
		vector<string> linkPagine;

	public:
		//costruttore
		WebPage(string titolo, string testo, vector<string> link){
			this->titoloPagina = titolo;
			this->testoPagina = testo;
			this->linkPagine = link;
		}
		
		//getters
		bool getConfrontoPagine(string pagina1, string pagina2){
			if (pagina1 == pagina2){
				return true;
			}else{
				return false;
			}
		}
		void getTitoloPagina(){
			cout << titoloPagina << endl;
		}
		void getTestoPagina(){
			cout << testoPagina << endl;
		}
		void getLinkPagine(){
			cout << linkPagine << endl;
		}
		
		//setters 
		void setNewLink(string newLink){
			linkPagine.push_back(newLink);
		}
};	

int main(){
		WebPage homepage("homepage", "Sono la homepage", "");
		homepage.getTitoloPagina();

		return 0;
}
