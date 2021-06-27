#include<list.h>
List::List()
{
    Head=0;
    IT=0;
    N=0;
}
void List::itNext()
{
    if(!IT)return;
    IT=IT->next;
}

bool List::pushCircular(Disparo *Dat)
{
    NodeList *P=NodeList::montaNode(Dat);
    if(!Head)
    {
        Head=P;
        P->next=P;
        P->prev=P;
    }else
    {
        (Head->prev)->next=P;
        P->prev=Head->prev;
        P->next=Head;
        Head->prev=P;
    }
    N++;
    return true;
}
bool List::searchCircular(int k)
{
    if(!Head)return false;

    NodeList*P=Head;
    for(;P->next!=Head && k!=P->D.getId();P=P->next);

    if(P->D.getId()!=k)return false;
    return true;
}
bool List::removeCircular(int k)
{
    if(!Head)return false;
    NodeList*P=Head;
    for(; P->next!=Head && P->D.getId()!=k; P=P->next);
    if(P->D.getId()!=k)return false;

    if(P->next==P)Head=0;
    else if(P==Head)Head=P->next;

    (P->next)->prev=P->prev;
    (P->prev)->next=P->next;
    N--;
    NodeList::desmontaNode(P);
    return true;
}
