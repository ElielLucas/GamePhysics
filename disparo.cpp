#include "disparo.h"

Disparo:: Disparo(pair<int, int> posicao, QChar identifica, int id, QString direcaoDisparo):
    Thing(posicao,identifica,id)
{
    this->direcaoDisparo=direcaoDisparo;

    imgAttack= new QImage("attack.png");
    imgEndAttack= new QImage("endFogo.png");
    quantidade = 0;
}

pair<int,int> Disparo::getPosicaoDestino()
{
    pair<int,int> p = getPosicao();
    if(direcaoDisparo=="D")
        return {p.first,p.second+1};
    else if(direcaoDisparo=="E")
        return {p.first,p.second-1};
    else if(direcaoDisparo=="C")
        return {p.first-1,p.second};
    else if(direcaoDisparo=="B")
        return {p.first+1,p.second};

    return {-1,-1};
}

void Disparo::moveToTargetPosition()
{
    if(direcaoDisparo=="D")
        moverDireita();
    else if(direcaoDisparo=="E")
        moverEsquerda();
    else if(direcaoDisparo=="C")
        moverCima();
    else if(direcaoDisparo=="B")
        moverBaixo();
}
