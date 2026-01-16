#include<iostream>
#include<vector>
using namespace std;

class VettorePazzo : public vector<unsigned>{
private:
    unsigned numeroPazzo;
public:
    VettorePazzo(unsigned np) : numeroPazzo(np){}

    void push_back(unsigned val){
        if (val % numeroPazzo != 0){
            vector<unsigned>::push_back(val);
        }
    }
    unsigned operator[](int i) const{
        // regola speciale: se dimensione e' multipla di numero pazzo
        if (size() % numeroPazzo == 0) {return 0;}

        // caso 1: i < 0 e |i| >= n
        if (i < 0 && static_cast<unsigned> (-1) >= size()){
            return vector<unsigned>:: operator[](0);
        }
        
        // Caso 2: i < 0 e |i| < n
        if (i < 0 && static_cast<unsigned>(-i) < size()) {
            return vector<unsigned>::operator[](size() + i);
        }
        
        // Caso 3: i >= 0 e i < n
        if (i >= 0 && static_cast<unsigned>(i) < size()) {
            return vector<unsigned>::operator[](i);
        }
        
        // Caso 4: i >= 0 e i >= n
        return vector<unsigned>::operator[](size() - 1);
    }

    bool operator==(const VettorePazzo&) const {
        return true;
    }

    bool operator<(const VettorePazzo& other) const {
        return numeroPazzo < other.numeroPazzo;
    }
};