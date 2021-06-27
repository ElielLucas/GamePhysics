#include<treeavl.h>
Tree::Tree()
{
    root=nullptr;
    lins=0;
    cols=0;
}

Tree::Tree(int lins,int cols)
{
    root=nullptr;
    this->lins=lins;
    this->cols=cols;

}

void Tree::swap(NodeTree*R1, NodeTree*R2)
{
    Thing x=R2->D;
    R2->D=R1->D;
    R1->D=x;
}

bool Tree::valida(pair<int,int> posi)
{
    return 0<=posi.first && posi.first<lins && 0<=posi.second && posi.second<cols;
}

QString Tree::getRoot()
{
    QString uu;
    if(root)uu= root->D.getClassificacao();
    throw QString(uu);

    return uu;

}

QString Tree::inorder()
{
    QString** grid=new QString*[lins], saida;
    for(int i=0;i<lins;i++)
    {
        grid[i]=new QString [cols];
        *grid[i]="";
    }


    inorderR(root,grid);

    for(int i=0; i<lins; i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j]=="")saida+="-";
            else saida+=grid[i][j];
        }
    }

    delete []grid;
    return saida;
}
void Tree::inorderR(NodeTree*R, QString **grid)
{
    if(R)
    {
       inorderR(R->left,grid);
       if(R->D.getClassificacao()=="o")//jogador
           grid[R->D.getPosicao().first][R->D.getPosicao().second]+="o";
       else if(R->D.getClassificacao()=="#")//pedra
          grid[R->D.getPosicao().first][R->D.getPosicao().second]+="#";
       else if(R->D.getClassificacao()=="&")//boss
           grid[R->D.getPosicao().first][R->D.getPosicao().second]+="&";

       inorderR(R->right,grid);
    }

}
bool Tree::moveRight(pair<int,int> posi)
{
    Thing aux,aaa;
    pair<int,int> posiAux=posi;
    posiAux.first=posi.first;
    posiAux.second=posi.second+1;
    if(!valida(posiAux) || search(posiAux,&aux))
    {
        return false;
    }
    remove(posi,&root,&aux);
    aux.moverDireita();
    if(!search(posi,&aaa))push(&aux);
    return true;
}

bool Tree::moveLow(pair<int,int> posi)
{
    Thing aux;
    pair<int,int> posiAux;
    posiAux.first=posi.first+1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || search(posiAux,&aux))
    {
        return false;
    }
    remove(posi,&root,&aux);
    aux.moverBaixo();
    push(&aux);
    return true;
}

bool Tree::moveLeft(pair<int,int> posi)
{
    Thing aux;
    pair<int,int> posiAux;
    posiAux.first=posi.first;
    posiAux.second=posi.second-1;
    if(!valida(posiAux) || search(posiAux,&aux))
    {
        return false;
    }
    remove(posi,&root,&aux);
    aux.moverEsquerda();
    push(&aux);
    return true;
}
bool Tree::moveUp(pair<int,int> posi)
{
    Thing aux;
    pair<int,int> posiAux;
    posiAux.first=posi.first-1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || search(posiAux,&aux))
    {
        return false;
    }
    remove(posi,&root,&aux);
    aux.moverCima();
    push(&aux);
    return true;
}
bool Tree::criarStoneRight(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first;
    posiAux.second=posi.second+1;
    if(!valida(posiAux) || search(posiAux,&aux1))return false;
    Thing aux(posiAux,'#',0);
    push(&aux);
    return true;
}
bool Tree::criarStoneLow(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first+1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || search(posiAux,&aux1))return false;
    Thing aux(posiAux,'#',0);
    push(&aux);
    return true;
}
bool Tree::criarStoneLeft(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first;
    posiAux.second=posi.second-1;
    if(!valida(posiAux) || search(posiAux,&aux1))return false;
    Thing aux(posiAux,'#',0);
    push(&aux);
    return true;
}

bool Tree::criarStoneUp(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first-1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || search(posiAux,&aux1))return false;
    Thing aux(posiAux,'#',0);
    push(&aux);
    return true;
}

bool Tree::quebrarStoneRight(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux=posi;
    posiAux.second++;
    if(!valida(posiAux) || !(search(posiAux,&aux1)) || ((search(posiAux,&aux1) && aux1.getClassificacao()=="o")))
        return false;

    remove(posiAux,&root,&aux1);
    return true;
}

bool Tree::quebrarStoneLow(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first+1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || !search(posiAux,&aux1) || aux1.getClassificacao()=="o")return false;
    remove(posiAux,&root,&aux1);
    return true;
}

bool Tree::quebrarStoneLeft(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first;
    posiAux.second=posi.second-1;
    if(!valida(posiAux) || !search(posiAux,&aux1) || aux1.getClassificacao()=="o")return false;
    remove(posiAux,&root,&aux1);
    return true;
}

bool Tree::quebrarStoneUp(pair<int,int> posi)
{
    Thing aux1;
    pair<int,int> posiAux;
    posiAux.first=posi.first-1;
    posiAux.second=posi.second;
    if(!valida(posiAux) || !search(posiAux,&aux1) || aux1.getClassificacao()=="o")return false;
    remove(posiAux,&root,&aux1);
    return true;
}

bool Tree::push(Thing *Dat)
{ 
   NodeTree* P=NodeTree::montaNode(Dat);
   if(!P)return false;
   return insert(&root,P);
}

bool Tree::pop(pair<int,int>k, Thing*Dat)
{
    remove(k,&root,Dat);
    return true;
}

bool Tree::search(pair<int,int>k, Thing*Dat)
{
    NodeTree*P=root;
    while(P && k!=P->D.getPosicao())
    {
        if(k<P->D.getPosicao())
        {
            P=P->left;
        }else
        {
            P=P->right;
        }
    }
    if(!P)return false;
    *Dat=P->D;
    return true;
}

bool Tree::insert(NodeTree**R, NodeTree*aux)
{
    if(!*R)
    {
        *R=aux;
        return true;
    }else
    {         
       if(aux->D < (*R)->D)
       {
            if(Tree::insert(&((*R)->left),aux))
            {
                if((*R)->fb==0)
                {
                    (*R)->fb=-1;
                    return true;
                }
                if((*R)->fb==1)
                {
                    (*R)->fb=0;
                    return false;
                }
                if((*R)->left->fb==-1)
                {
                    Tree::RSD(R);
                    return false;
                }
                Tree::RDD(R);
                return false;
            }
            return false;
        }
       if(aux->D > ((*R)->D))
       {
           if(Tree::insert(&((*R)->right),aux))
           {
               if((*R)->fb==0)
               {
                   (*R)->fb=1;
                   return true;
               }
               if((*R)->fb==-1)
               {
                   (*R)->fb=0;
                   return false;
               }
               if((*R)->right->fb==1)
               {
                   Tree::RSE(R);
                   return false;
               }
               Tree::RDE(R);
               return false;
           }
           return false;
       }
    }
    return true;
}

bool Tree::remove(pair<int,int> k,NodeTree**R, Thing*Dat)
{
    if(!*R)return false;
    if(k<(*R)->D.getPosicao())
    {
        if(Tree::remove(k,&((*R)->left),Dat))
        {
            if((*R)->fb==0)
            {
                (*R)->fb=1;
                return false;
            }
            if((*R)->fb==-1)
            {
                (*R)->fb=0;
                return true;
            }
            if((*R)->right->fb==1)
            {
                Tree::RSE(R);
                return true;
            }
            if((*R)->right->fb==0)
            {
                Tree::RSE(R);
                return false;
            }
            Tree::RDE(R);
            return true;
        }
        return false;
    }
    if(k>(*R)->D.getPosicao())
    {
        if(Tree::remove(k,&((*R)->right),Dat))
        {
            if((*R)->fb==0)
            {
                (*R)->fb=-1;
                return false;
            }
            if((*R)->fb==1)
            {
                (*R)->fb=0;
                return true;
            }
            if((*R)->left->fb==-1)
            {
                Tree::RSD(R);
                return true;
            }
            if((*R)->left->fb==0)
            {
                Tree::RSD(R);
                return false;
            }
            Tree::RDD(R);
            return true;
        }
        return false;
    }
    if(!(*R)->left)
    {
        NodeTree*aux=(*R);
        *R=aux->right;
        *Dat=NodeTree::desmontaNode(aux);
        return true;
    }
    if(!(*R)->right)
    {
        NodeTree*aux=*R;
        *R=aux->left;
        *Dat=NodeTree::desmontaNode(aux);
        return true;
    }
    NodeTree*aux=Tree::maximus((*R)->left);
    swap((*R),aux);
    if(Tree::remove(k,&((*R)->left),Dat))
    {
        if((*R)->fb==0)
        {
            (*R)->fb=1;
            return false;
        }
        if((*R)->fb==-1)
        {
            (*R)->fb=0;
            return true;
        }
        if((*R)->right->fb==1)
        {
            Tree::RSE(R);
            return true;
        }
        if((*R)->right->fb==0)
        {
            Tree::RSE(R);
            return false;
        }
        Tree::RDE(R);
        return true;
    }
    return false;
}

NodeTree* Tree::maximus(NodeTree*R)
{
    if(!R)return nullptr;
    if(!R->right)return R;
    return maximus(R->right);
}

void Tree::RSD(NodeTree**R)
{
    NodeTree*A=*R;
    NodeTree*B=A->left;
    A->left=B->right;
    B->right=A;
    *R=B;
    if(B->fb==-1)
    {
        A->fb=B->fb=0;
    }else
    {
        A->fb=-1;
        B->fb=+1;
    }
}

void Tree::RSE(NodeTree**R)
{
    NodeTree*A= *R;
    NodeTree*B=A->right;
    A->right=B->left;
    B->left=A;
    *R=B;
    if(B->fb==1)
    {
        A->fb=B->fb=0;
    }else
    {
        A->fb=1;
        B->fb=-1;
    }
}

void Tree::RDD(NodeTree**R)
{
    NodeTree*A=*R;
    NodeTree*B=A->left;
    NodeTree*C=B->right;
    A->left=C->right;
    B->right=C->left;
    C->left=B;
    C->right=A;
    *R=C;
    if(C->fb==1)
    {
        A->fb=0;
        B->fb=-1;
    }else
    {
        if(C->fb==-1)
        {
            A->fb=1;
            B->fb=0;
        }else
        {
            A->fb=0;
            B->fb=0;
        }
    }
    C->fb=0;
}

void Tree::RDE(NodeTree**R)
{
    NodeTree*A=*R;
    NodeTree*B=A->right;
    NodeTree*C=B->left;
    A->right=C->left;
    B->left=C->right;
    C->left=A;
    C->right=B;
    *R=C;
    if(C->fb==1)
    {
        A->fb=-1;
        B->fb=0;
    }else
    {
        if(C->fb==-1)
        {
            A->fb=0;
            B->fb=1;
        }else
        {
            A->fb=0;
            B->fb=0;
        }
    }
    C->fb=0;
}
