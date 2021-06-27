#include "nodestack.h"

NodeStack::NodeStack()
{
    next=0;
    valorAcao=0;
}
void NodeStack::atribuirValor(QChar C)
{
    if(C=='M')
        valorAcao=1;
    else if(C=='A')
        valorAcao=1;
    else if(C=='C')
        valorAcao=4;
    else if(C=='D')
        valorAcao=3;
}
NodeStack* NodeStack::montaNode(pair<QChar,QChar> *Dat)
{
    NodeStack* P=new NodeStack;
    if(P)
    {
        P->D=*Dat;
    }
    return P;
}
pair<QChar,QChar> NodeStack::desmontaNode(NodeStack *P)
{
    pair<QChar,QChar> x=P->D;
    delete P;
    return x;
}
