#include <iostream>
#include <limits.h>

using namespace std;

int main(){

    // n = n x (n-1) x (n-2) ... (x1)
    int n;
    int fattn = 1; //memorizza il valore da moltiplicare 
    cin >> n; 
    int currN = n; // numero corrente
    if (n>0){
        while(){
            fattn = fattn * curr_n;
            curr_n--;
        }
    }
    cout << "fattoriale" << endl;
    return 0;
}