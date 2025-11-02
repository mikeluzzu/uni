// chiedere al'utente un numero e stampare i primi N numeri primi. Si ricorda
//che un numero è primo se è maggiore di 1 e se è divisibile solo per 1 o per
//se stesso

#include <iostream>

using namespace std;

bool isPrime(int &n){
    if (n <= 1){
        return false;
    }
    for(int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }

    }
    return true;
}

int main(){
    cout << "inserisci un numero\n";
    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        if (isPrime(n)){
            cout << i << endl;
        }
    }
    return 0;
}