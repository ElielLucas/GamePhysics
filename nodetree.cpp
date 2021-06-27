#include<nodetree.h>
NodeTree::NodeTree()
{
    left=0;
    right=0;
    fb=0;
}
NodeTree* NodeTree::montaNode(Thing *Dat)
{
    NodeTree*P=new NodeTree;
    if(P)P->D=*Dat;
    return P;
}
Thing NodeTree::desmontaNode(NodeTree* P)
{
    Thing aux=P->D;
    delete P;
    return aux;
}
