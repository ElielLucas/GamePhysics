#ifndef NODE_H
#define NODE_H
#include<thing.h>

class NodeTree
{
    public:
        Thing D;
        NodeTree* left;
        NodeTree* right;
        int fb;
        NodeTree();
        static NodeTree* montaNode(Thing *Dat);
        static Thing desmontaNode(NodeTree* P);
};



#endif // NODE_H
