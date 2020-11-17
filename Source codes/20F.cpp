#include <iostream>
using namespace std;
template<typename T>
class Node
{
private:
    Node<T> *leftNode ;
    Node<T> *rightNode;
    Node<T> *parent   ;
         T   value    ;
public:
    Node(T val, Node<T> *par)
    {
        this.value = val;
        this.parent = par;
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
    void Insert(T val)
    {
        if(val < this.value)
        {
            if(this->leftNode == NULL)
            {
                leftNode = new Node(val, &this);
            }
            else
            {
                leftNode->Insert(val);
            }
            
        }
        else if(val > this->value)
        {
            if(this->rightNode == NULL)
            {
                rightNode = new Node(val, &this);
            }
            else
            {
                rightNode->Insert(val);
            }
            
        }
    }
    
};
int main()
{
    return 0;
}