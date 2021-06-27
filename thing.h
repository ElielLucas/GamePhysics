#ifndef THING_H
#define THING_H
#include<iostream>
#include<QImage>
#include<QTime>
#include<QMediaPlayer>
#include<QString>
#include<utility>
using namespace std;

class Thing
{
private:
    int id;
    pair<int,int> posicao;
    QChar classificacao;
    pair<bool,QTime> movementTime, timeReached;
public:  
    Thing();
    Thing(pair<int, int> posicao, QChar identifica, int id);

    void setPosicao(pair<int,int> p){posicao=p;}
    void setId(int id){this->id=id;}
    void setClassificacao(QChar c){classificacao=c;}
    QChar getClassificacao(){return classificacao;}
    int getId(){return id;}
    pair<int,int> getPosicao(){return posicao;}

    void setMovementTime(pair<bool,QTime> x){movementTime = x;}
    pair<bool,QTime> getMovementTime()const{return movementTime;}

    void setTimeReached(pair<bool,QTime> x){timeReached = x;}
    pair<bool,QTime> getTimeReached()const{return timeReached;}

    void moverDireita(){posicao.second++;}
    void moverEsquerda(){posicao.second--;}
    void moverCima(){posicao.first--;}
    void moverBaixo(){posicao.first++;}

    bool operator < (Thing &P);
    bool operator > (Thing &P);
    bool operator < (pair<int, int> &P);
    bool operator > (pair<int, int> &P);
};


#endif // THING_H
