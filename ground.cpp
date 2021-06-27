#include "ground.h"

Ground::Ground()
{
    imgGround = new QImage("grama.jpg");
}
Ground::Ground(pair<int, int> posicao, QChar identifica, int id):
    Thing(posicao, identifica, id)
{
    imgGround = new QImage("grama.jpg");
}
