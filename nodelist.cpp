#include<nodelist.h>
NodeList::NodeList()
{
    next=0;
    prev=0;
}
NodeList* NodeList::montaNode(Disparo *Dat)
{
    NodeList* P=new NodeList;
    if(P) P->D=*Dat;
    return P;
}
Disparo NodeList::desmontaNode(NodeList *P)
{
    Disparo x=P->D;
    delete P;
    return x;
}
