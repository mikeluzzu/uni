#ifndef WEBSITE_H
#define WEBSITE_H

#include "WebPage.h"

#include <queue>
#include <algorithm>

using namespace std;

class WebSite{
    private:   
        WebPage homepage;

    public:
        // constructor
        WebSite() = default;
        WebSite(const WebPage& w) : homepage(w){}

        int find_webpage(const WebPage& target) const{
            vector<WebPage> visitati;
            queue<WebPage> daVisitare;
            
            daVisitare.push(homepage);
            visitati.push_back(homepage);

            int level = 0;

            while (!daVisitare.empty()){
                int levelSize = daVisitare.size();
                
                for (int i = 0; i < levelSize; i++){
                    WebPage curr_page = daVisitare.front(); // prendo in lettura la pagina corrente 
                    daVisitare.pop(); // estraggo la pagina corrente

                    if (curr_page == target)
                        return level;

                    for (WebPage* w : curr_page.getLink()){
                        if (find(visitati.begin(), visitati.end(), *w) == visitati.end()){
                            visitati.push_back(*w);
                            daVisitare.push(*w);
                        }
                    }
                }
                level++;
            }
            return -1;
        }
    

};

#endif