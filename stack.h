#ifndef STACK_H
#define STACK_H
#include<QString>
#include<nodestack.h>
#include<utility>
using namespace std;
typedef pair<QChar, QChar> pairr;
class Stack
{
    private:
        NodeStack* Top;
        int N;
    public:
        Stack();
        bool isEmpty(){return !N;}
        int size(){return N;}
        pairr top();
        NodeStack* topNode();
        pairr pop();
        bool push(pairr* Dat);
        void clear();
};



#endif // STACK_H
