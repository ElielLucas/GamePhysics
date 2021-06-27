#ifndef GROUND_H
#define GROUND_H
#include<thing.h>

class Ground: public Thing
{   
private:
    QImage* imgGround;
public:
    Ground();
    Ground(pair<int, int> posicao, QChar identifica, int id);

    QImage* getImgGround(){return imgGround;}
};

#endif // GROUND_H
