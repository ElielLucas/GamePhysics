#ifndef ANDARDUNGEON_H
#define ANDARDUNGEON_H
#include<QString>
#include<iostream>
#include<fstream>
#include<treeavl.h>
#include<stone.h>
#include<utility>
using namespace std;

class andarDungeon
{
    int lins;
    int cols;
    string *map;

public:
    andarDungeon(string arquivo);
    QString print();
    int getLins(){return lins;}
    int getCols(){return cols;}
    char get(int i, int j){return map[i][j];}
    bool livre(int i, int j){return map[i][j]=='-';}
    Tree getTree();

};

#endif // ANDARDUNGEON_H
