#ifndef DISPARO_H
#define DISPARO_H
#include<thing.h>
#include<QString>
#include<utility>

class Disparo: public Thing
{
private:
    QString direcaoDisparo;

    QImage* imgAttack;
    QImage* imgEndAttack;
    int quantidade;
public:
    Disparo(){quantidade=0;}
    Disparo(pair<int, int> posicao, QChar identifica, int id, QString direcaoDisparo);
    void setDirecaoDisparo(QString x){direcaoDisparo = x;}
    QString getDirecaoDisparo(){return direcaoDisparo;}
    void setQuantidade(int x){quantidade=x;}
    int getQuantidade(){return quantidade;}
    pair<int,int> getPosicaoDestino();
    void moveToTargetPosition();

    QImage* getImgAttack(){return imgAttack;}
    QImage* getImgEndAttack(){return imgEndAttack;}
};

#endif // DISPARO_H
