#ifndef MONSTRO_H
#define MONSTRO_H
#include<livingelement.h>

class Monstro: public LivingElement
{
private:
    QMediaPlayer grito;
    QImage** imgMonstro;

public:
    Monstro(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento);
    void playGrito(){grito.play();}

    QImage* getImgMonstro(int i){return imgMonstro[i];}
};

#endif // MONSTRO_H
