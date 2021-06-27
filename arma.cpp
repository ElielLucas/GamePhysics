#include "arma.h"

Arma::Arma(int damage, QString typeAttack, int usageTime)
{
    this->damage=damage;
    this->typeAttack=typeAttack;
    this->usageTime=usageTime;
    firing= new Disparo;

    somAtaque.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/fogo.mp3"));
}


void Arma::disparar(pair<int, int> startingPosition, QString dir)
{
    if(firing->getQuantidade()==0)
    {
        firing = new Disparo (startingPosition,'*',0,dir);
        firing->setQuantidade(1);
    }
}

posiType Arma::updateBulletPositions(QString map, int M)
{
    posiType saida;
    if(firing->getQuantidade()>0 && firing->getMovementTime().first)
    {
        somAtaque.play();
        pair<int,int> x = firing->getPosicaoDestino();
        QChar classif = map[x.first*M+x.second];

        if(classif!='#' && classif!='&')
              firing->moveToTargetPosition();
        else
        {

            if(classif=='#')saida={firing->getPosicao(),'#'};
            else if(classif=='&')saida={x,'&'};

            somAtaque.stop();
        }
        return saida;
    }
    return {{-1,-1},' '};
}

