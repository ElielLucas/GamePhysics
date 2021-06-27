#ifndef JOGADOR_H
#define JOGADOR_H
#include<arma.h>
#include<livingelement.h>

class Jogador: public LivingElement
{
private:
    Arma* weapon;    
    QMediaPlayer somPassos;
    QImage** imgPlayer;
public:
    Jogador(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento);
    Arma* getWeapon()const{return weapon;}

    void playSomPassos(){somPassos.play();}
    void stopSomPassos(){somPassos.stop();}

    QImage* getImgPlayer(int i){return imgPlayer[i];}
};

#endif // JOGADOR_H
