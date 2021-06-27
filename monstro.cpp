#include "monstro.h"


Monstro::Monstro(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento):
    LivingElement(posicao,identifica,id,direcao,HP,velocidadeMovimento)
{
    imgMonstro = new QImage*[8];

    imgMonstro[0] = new QImage("bossFrente.png");
    imgMonstro[1] = new QImage("bossCostas.png");
    imgMonstro[2] = new QImage("bossDir.png");
    imgMonstro[3] = new QImage("bossEsq.png");
    imgMonstro[4] = new QImage("bossDiagInfDir.png");
    imgMonstro[5] = new QImage("bossDiagInfEsq.png");
    imgMonstro[6] = new QImage("bossDiagSupDir.png");
    imgMonstro[7] = new QImage("bossDiagSupEsq.png");

    grito.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/grito.mp3"));
}
