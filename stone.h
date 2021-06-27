#ifndef STONE_H
#define STONE_H
#include<thing.h>

class Stone: public Thing
{
private:
    QMediaPlayer somQuebrar;
    QMediaPlayer somCriar;
    QImage* imgStone;
public:
    Stone();
    Stone(pair<int, int> posicao, QChar identifica, int id);
    void playSomQuebrar(){somQuebrar.play();}
    void stopSomQuebrar(){somQuebrar.stop();}
    void playSomCriar(){somCriar.play();}
    void stopSomCriar(){somCriar.stop();}

    QImage* getImgStone(){return imgStone;}
};

#endif // STONE_H
