#ifndef TREE_H
#define TREE_H
#include<nodetree.h>
#include<nodelist.h>
enum Direcao
{
    CIMA, BAIXO, DIREITA, ESQUERDA
};

class Tree
{
    private:
       NodeTree* root;
       int lins, cols;
    public:
        Tree();
        Tree(int lins,int cols);
        bool push(Thing *Dat);
        bool pop(pair<int,int>k, Thing*Dat);
        static void inorderR(NodeTree*R, QString **grid);
        QString inorder();
        static void RSD(NodeTree**R);
        static void RSE(NodeTree**R);
        static void RDD(NodeTree**R);
        static void RDE(NodeTree**R);
        static bool insert(NodeTree**R, NodeTree*aux);
        static bool remove(pair<int,int>k,NodeTree**R, Thing*Dat);
        bool search(pair<int,int>k, Thing*Dat);
        bool valida(pair<int,int>posi);
        bool moveRight(pair<int,int> posi);
        bool moveLow(pair<int,int> posi);
        bool moveLeft(pair<int,int> posi);
        bool moveUp(pair<int,int> posi);
        bool criarStoneRight(pair<int,int> posi);
        bool criarStoneLow(pair<int,int> posi);
        bool criarStoneLeft(pair<int,int> posi);
        bool criarStoneUp(pair<int,int> posi);
        bool quebrarStoneRight(pair<int,int> posi);
        bool quebrarStoneLow(pair<int,int> posi);
        bool quebrarStoneLeft(pair<int,int> posi);
        bool quebrarStoneUp(pair<int,int> posi);       
        static NodeTree* maximus(NodeTree*R);
        static void swap(NodeTree*R1, NodeTree*R2);
        void limparArray();

        QString getRoot();
};

#endif // TREE_H
