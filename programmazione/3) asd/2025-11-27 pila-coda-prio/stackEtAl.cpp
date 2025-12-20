#include<iostream>
#include<list>
#include<cassert>

using namespace std;
// creazione del template della classe generale stack 
template<typename T>
class Stack{
private:
   list<T> S;
public:
    void push(T el){S.push_back(el);}
    void pop(){assert(!S.empty()); S.pop_back();}
    bool empty(){return S.empty();}
    size_t size(){return S.size();}
    T top () {return S.back();}
};


// classe template generale per la coda
template<typename T>
class Queue{
private:
   list<T> S;
public:
    void enqueue(T el){S.push_back(el);}
    void dequeue(){assert(!S.empty()); S.pop_front();}
    bool empty(){return S.empty();}
    size_t size(){return S.size();}
    T front () {return S.front();}
};

//classe coda ereditando la lista
template<typename T>
class QueueINH:protected list<T>{
public:
    void enqueue(T el){this->push_back(el);}
    void dequeue(){assert(!empty()); list<T>::pop_front();}
    
    //bool empty(){return empty();}
    using  list<T>::empty;
    size_t size(){return list<T>::size();}
    T front () {return list<T>::front();}
};

// classe coda che eredita la lista con priorita
template<typename T>
class QueueINHwithPriority:public QueueINH<T>{
public:
    void enqueue(T el){
        typename list<T>::iterator it=this->begin();
        while(it!=this->end()&&el<=(*it))
        {
               it++;
        }
        this->insert(it,el);
}    


};


                
int main()
{
   Stack<int> H;
   if (!H.empty())
     H.pop();
   QueueINHwithPriority<int>  Q;
   Q.enqueue(3);
   Q.enqueue(2);
   Q.enqueue(4);
   cout<<Q.front()<<" "<<endl;
   Q.dequeue();
   cout<<Q.front()<<" "<<endl;
   Q.dequeue();
   cout<<Q.front()<<" "<<endl;
      
   if(Q.empty())
      cout<<"coda vuota"<<endl;
 }
    
