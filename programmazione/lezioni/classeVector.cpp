#include <iostream>
#include <vector>
using namespace std;

class VectorOfInt{
    private:
        int * array;
        unsigned size;
        unsigned capacity;

    public:
        VectorOfInt():array(nullptr), capacity(0), size(0){

        }
        
        VectorOfInt(unsigned c): array(new int[c], capacity(c), size(0)){

        }
        ~VectorOfInt(){cout << "distruttore" << endl;
            delete []array;
        }

        void resize(unsigned C){
            //supponiamo C>capacity
            if (C>=capacity){
                    int * temp = new int[C];
                    for (unsigned i=0; i < size; i++){
                        temp[i] = array[i];
                    }
                    delete []array; 
                    array = temp;
                    capacity = C;
            } else if (C<capacity){

            }
            
        }
        
        void push_back(int el){

            if(size == capacity){
                resize(capacity*2); //aumento la capacity 
            }
            array[size++]=el; //stessa cosa: array[size]=el ; size +=1; 
        }

        //implementare questo costruttore:

        VectorOfInt(const VectorOfInt &C)
        // e questo operatore:
        //operator =

};


int main(){
    VectorOfInt V;
    V.push_back(5);
    V.push_back(2);
    V[0]=5;
    cout << V[0];  

}

/*non devono mai mancare:  distruttore, costruttore per copia, operatore assegnamento

nei vector abbiamo 2 parametri: capacity: quando spazio ho allocato e size: quanti elementi ho allocato. La size deve sempre essere minore uguale 
della capacity, quindi se ho una size maggiore devo incrementare anche la capacity.

se creo un oggetto dinamico devo creare un distruttore che lo dealloca
*/   
