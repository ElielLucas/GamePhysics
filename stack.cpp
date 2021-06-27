#include "stack.h"

Stack::Stack()
{
    Top=0;
    N=0;
}

pairr Stack::top()
{
    if(Top)
    {
        return Top->D;
    }
}
NodeStack* Stack::topNode()
{
    if(Top)
    {
        return Top;
    }
}
bool Stack::push(pairr *Dat)
{
    NodeStack* P=NodeStack::montaNode(Dat);
    if(!P) return false;
    P->atribuirValor(Dat->first);
    P->next=Top;
    Top=P;
    N++;
    return true;
}
pairr Stack::pop()
{
     NodeStack* P=Top;
     Top=Top->next;
     N--;
     return NodeStack::desmontaNode(P);
}
void Stack::clear()
{
    while(size())
    {
        pop();
    }
}
