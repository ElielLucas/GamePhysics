#ifndef NODELIST_H
#define NODELIST_H
#include<disparo.h>
class NodeList
{
    public:
    Disparo D;
    NodeList *next;
    NodeList *prev;
    NodeList();

    static NodeList* montaNode(Disparo *Dat);
    static Disparo desmontaNode(NodeList *P);
};


#endif // NODELIST_H
