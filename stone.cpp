#include "stone.h"
Stone::Stone()
{
   imgStone = new QImage("wall.jpg");

   somCriar.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/criarStone.mp3"));
   somQuebrar.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/quebrarStone.mp3"));
}
Stone::Stone(pair<int, int> posicao, QChar identifica, int id):
    Thing(posicao, identifica, id)
{
   imgStone = new QImage("/Efeitos/wall.jpg");

   somCriar.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/criarStone.mp3"));
   somQuebrar.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/quebrarStone.mp3"));
}
