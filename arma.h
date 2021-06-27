#ifndef ARMA_H
#define ARMA_H
#include<list.h>
#include<stack>
#include<QString>
#include<QImage>
#include<QMediaPlayer>
#include<stdlib.h>
typedef pair<pair<int,int>,char> posiType;
class Arma
{
private:
    Disparo* firing;
    QString typeAttack;
    float damage;
    int usageTime;

    QMediaPlayer somAtaque;
public:
    Arma(int damage, QString typeAttack, int usageTime);
    float getDamage()const{return damage;}
    void descarregar(){firing->setQuantidade(0);}

    void disparar(pair<int, int> startingPosition, QString dir);
    Disparo * getFiring()const{return firing;}
    posiType updateBulletPositions(QString map, int M);

    void playSomAtaque(){somAtaque.play();}
    void stopSomAtaque(){somAtaque.stop();}
};

#endif // ARMA_H
