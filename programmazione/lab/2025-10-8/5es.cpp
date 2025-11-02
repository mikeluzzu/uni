#include <iostream>
using namespace std;

int main(){
    int x = 2, y = 3;
    int& a = x;
    cout << a << endl;
    cout << &a << " " << &x << " " << &y << " " << endl;
    a = y;
    cout << a << x << y << endl;
    a = 7;
    cout << a << x << y << endl;
    cout << &a << " " << &x << " " << &y << " " << endl;
}