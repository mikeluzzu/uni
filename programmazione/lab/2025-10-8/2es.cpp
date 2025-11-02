#include <iostream>
using namespace std;

int main(){
    char* pc, c;
    pc = &c;

    for (c = 'A'; c <= 'Z'; c++){
        cout << pc << " ";
    }
    cout << endl;
    return 0;
}