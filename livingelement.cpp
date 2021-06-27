#include "livingelement.h"

LivingElement::LivingElement(pair<int, int> posicao, QChar identifica, int id, QString direcao, float HP, float velocidadeMovimento):
    Thing(posicao, identifica, id)
{
    this->direcao=direcao;
    this->HP=HP;
    this->velocidadeMovimento=velocidadeMovimento;   
}

bool LivingElement::receberDano(int dano)
{
    HP-=dano;
    if(HP<=0)
    {
        HP=0;
        return true;
    }
    return false;
}
