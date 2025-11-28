using namespace std;
class NodeInt{
    friend class ListInt;
    private:
            int value;
            NodeInt * nextNode;
            NodeInt (int val) : value(val), nextNode(nullptr){};
};

class ListInt{
    NodeInt * first;
    NodeInt * last;
    public:
            ListInt(): first(nullptr), last(nullptr){}
            void pushBack(int v){
                NodeInt * newNode = new NodeInt(v);
                if (empty()){
                    first = last = newNode;
                } else {
                    last->nextNode = newNode; 
                    last = newNode;
                }
            }
            bool empty(){return first == nullptr;}
            bool popFront(){
                if (empty()){
                    return false;
                    NodeInt * tmp = first;
                    first = first->nextNode;
                }else{

                }
            }
            void print(){
                NodeInt * ptr=first;
                while (ptr != nullptr){
                    cout << ptr->value << " ";
                }
                ptr = ptr->nextNode;
            }
    ~distrNodeInt(){
        while (first != nullptr){
        NodeInt * tmp = first;
        first = first->nextNode;
        delete tmp;
    }
    }
};
int main(){
    ListInt T; 
    T.push_back(3);
    T.print();
    cout << endl;

    T.popFront();
}