

#include<iostream>
using namespace std;

class Cerchio
{
private:
    float x,y;
    float raggio;
public:
    float getRaggio() //metodo getter
    {
        return raggio;
    }    
    float getX() //metodo getter
    {
        return x;
    }    
    float getY() //metodo getter
    {
        return y;
    }    

    void setRaggio(float h)
    {
        if (h<0)
        {
             cout<<"nuovo valore negativo, modifica non apportata";
             return;
        }
        raggio = h;
    }
};


int main()
{
   Cerchio C;
    Cerchio K;
    C.setRaggio(-2);
    cout<<C.getRaggio();

   //C.raggio=-4;
}
