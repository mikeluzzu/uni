#ifndef WEBPAGE_H
#define WEBPAGE_H

#include<string>
#include<vector>
#include<iostream>

using namespace std;

class WebPage{

    private:
        const string titolo;
        const string testo;
        vector<WebPage> link;
    public:
        // constructors
        WebPage() = default;

        // getters
        string getTitolo()const{return titolo;}
        string getTesto()const {return testo;}
        const vector<WebPage*>& getLink()const {return link;}
        
        // setters
        void aggiungiLink(vector<WebPage*>& w){this->link.push_back(w);} 

        // operators
        bool operator == (const WebPage& other) {return titolo == other.getTitolo();}
        
        
};


#endif