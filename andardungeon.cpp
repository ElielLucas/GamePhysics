#include "andardungeon.h"

andarDungeon::andarDungeon(string arquivo)
{
    string aux="";
    ifstream arq(arquivo);
    arq>>lins;
    arq>>cols;

    arq.ignore();
    map=new string [lins];
    for(int i=0;i<lins;i++)
    {
        getline(arq,aux);
        map[i]=aux;
    }
}

Tree andarDungeon::getTree()
{
    Tree saida(lins,cols);

    int i=0;
    for(int i=0; i<lins;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(map[i][j]=='#')
            {

                pair<int,int> posi(i,j);
                Thing stone(posi,'#',0);
                saida.push(&stone);
            }
        }
    }

    return saida;
}

QString andarDungeon::print()
{
    QString saida="";

    for(int i=0;i<lins;i++)
    {
        saida+=QString::fromStdString(map[i])+"\n";
    }

    throw QString(saida);

    return saida;
}
