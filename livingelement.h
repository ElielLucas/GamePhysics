#ifndef LIVINGELEMENT_H
#define LIVINGELEMENT_H
#include<thing.h>

class LivingElement:public Thing
{
private:
    QString direcao;
    float HP;
    float velocidadeMovimento;   
public:
    LivingElement(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento);
    void setHp(float HP){this->HP=HP;}
    void setDirecao(QString d){direcao=d;}
    QString getDirecao(){return direcao;}
    float getVelocidadeMovimento()const{return velocidadeMovimento;}    
    bool receberDano(int dano);

//    virtual QImage* getImgObj(int i)override;
//    virtual void setImgObj()override;
};

#endif // LIVINGELEMENT_H
