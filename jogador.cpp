#include "jogador.h"

Jogador::Jogador(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento):
    LivingElement(posicao,identifica,id, direcao, HP,velocidadeMovimento)
{
    weapon = new Arma(20, "magia", 0);

    imgPlayer = new QImage*[4];
    imgPlayer[0] = new QImage("playerFrente.png");
    imgPlayer[1] = new QImage("playerCostas.png");
    imgPlayer[2] = new QImage("playerDir.png");
    imgPlayer[3] = new QImage("playerEsq.png");

    somPassos.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/passos.mp3"));
    somPassos.setVolume(30);
}

