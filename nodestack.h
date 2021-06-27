#ifndef NODESTACK_H
#define NODESTACK_H
#include<utility>
#include<QString>
using namespace std;
class NodeStack
{
    public:
    pair<QChar,QChar> D;
    int valorAcao;
    NodeStack *next;
    NodeStack();
    void atribuirValor(QChar C);
    static NodeStack* montaNode(pair<QChar,QChar> *Dat);
    static pair<QChar,QChar> desmontaNode(NodeStack *P);
};

#endif // NODESTACK_H
