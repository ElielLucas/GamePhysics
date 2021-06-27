#include<thing.h>
Thing::Thing()
{
    posicao.first=0;
    posicao.second=0;
    classificacao=' ';
    id=0;
    movementTime= {true,QTime::currentTime()};
    timeReached= {false,QTime::currentTime()};
}

Thing::Thing(pair<int, int> posicao, QChar identifica, int id)
{      
    this->posicao=posicao;
    this->classificacao=identifica;
    this->id=id;

    movementTime= {true,QTime::currentTime()};
    timeReached= {false,QTime::currentTime()};
}
bool Thing::operator < (Thing &P)
{
    if(posicao.first==P.posicao.first)return posicao.second < P.posicao.second;

    return posicao.first<P.posicao.first;
}
bool Thing::operator > (Thing &P)
{
    if(posicao.first==P.posicao.first)return posicao.second > P.posicao.second;

    return posicao.first>P.posicao.first;
}
bool Thing::operator < (pair<int, int> &P)
{
    if(posicao.first==P.first)return posicao.second < P.second;

    return posicao.first<P.first;
}
bool Thing::operator > (pair<int, int> &P)
{
    if(posicao.first==P.first)return posicao.second > P.second;

    return posicao.first>P.first;
}
