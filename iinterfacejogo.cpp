#include "iinterfacejogo.h"
#include "ui_iinterfacejogo.h"

IInterfaceJogo::IInterfaceJogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IInterfaceJogo)
{
    ui->setupUi(this);

    somAmbiente.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/fundo.mp3"));
    somAmbiente.setVolume(10);
    somAmbiente.play();
    somMonstro = new QMediaPlayer[4];
    somMonstro[0].setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/stare1.mp3"));
    somMonstro[1].setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/stare2.mp3"));
    somMonstro[2].setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/stare3.mp3"));
    somMonstro[3].setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/stare4.mp3"));

    try
    {
        dD = new andarDungeon("mapaInicial.txt");

        collision= dD->getTree();
        currentMap.resize(dD->getLins()*dD->getCols());

        player= new Jogador({8,3},'o',0,"B",100,200);
        boss= new Monstro({3,27},'&',0,"D", 200,400);

        collision.push(player);
        collision.push(boss);

    }  catch (QString erro) {
         QMessageBox::information(this,"Erro",erro);
    }

}

IInterfaceJogo::~IInterfaceJogo()
{
    somAmbiente.stop();
    delete ui;
}

void IInterfaceJogo::mousePressEvent(QMouseEvent *event)
{
    switch (event->buttons())
    {
        case Qt::LeftButton:
                if(player->getDirecao()=="D")criarDireita();
                else if(player->getDirecao()=="E")criarEsquerda();
                else if(player->getDirecao()=="C")criarCima();
                else if(player->getDirecao()=="B")criarBaixo();
            break;
        case Qt::RightButton:
                if(player->getDirecao()=="D")quebrarDireita();
                else if(player->getDirecao()=="E")quebrarEsquerda();
                else if(player->getDirecao()=="C")quebrarCima();
                else if(player->getDirecao()=="B")quebrarBaixo();
            break;
        case Qt::MiddleButton:
                if(player->getDirecao()=="D")
                {
                    player->getWeapon()->disparar(player->getPosicao(),"D");
                }else if(player->getDirecao()=="E")
                {                  
                    player->getWeapon()->disparar(player->getPosicao(),"E");
                }else if(player->getDirecao()=="C")
                {                  
                    player->getWeapon()->disparar(player->getPosicao(),"C");
                }else if(player->getDirecao()=="B")
                {                   
                    player->getWeapon()->disparar(player->getPosicao(),"B");
                }
            break;
    }  
    update();
}
void IInterfaceJogo::keyPressEvent(QKeyEvent *event)
{       
    switch (event->key())
    {
        case Qt::Key_A:
            if(player->getDirecao()=="E")
                moverEsquerda();
            else {player->setDirecao("E"); update();}
            break;
        case Qt::Key_W:
            if(player->getDirecao()=="C")
                moverCima();
            else {player->setDirecao("C");update();}
            break;
        case Qt::Key_S:          
            if(player->getDirecao()=="B")
                moverBaixo();
            else {player->setDirecao("B");update();}
            break;
        case Qt::Key_D:
            if(player->getDirecao()=="D")
                moverDireita();
            else {player->setDirecao("D");update();}
            break;
    }

}

void IInterfaceJogo::paintEvent(QPaintEvent *event)
{
    try
    {
        somAmbiente.play();
        int lins=dD->getLins();
        int cols=dD->getCols();

        int w= width();
        int h= height();

        currentMap = collision.inorder();
        administerShots();

        int cw=w/cols;
        int ch=h/lins;

        QPainter painter(this);

        for(int i=0;i<lins;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(currentMap[i*cols+j]=='-')painter.drawImage(QRect(j*cw, i*ch, cw, ch), *gramaAux.getImgGround());
                else if(currentMap[i*cols+j]=='o')
                {
                   painter.drawImage(QRect(j*cw, i*ch, cw, ch), *gramaAux.getImgGround());
                   if(player->getDirecao()=="D") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *player->getImgPlayer(2));
                   else if(player->getDirecao()=="C") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *player->getImgPlayer(1));
                   else if(player->getDirecao()=="B") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *player->getImgPlayer(0));
                   else if(player->getDirecao()=="E") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *player->getImgPlayer(3));
                }
                else if(currentMap[i*cols+j]=='&')
                {
                   painter.drawImage(QRect(j*cw, i*ch, cw, ch), *gramaAux.getImgGround());
                   if(boss->getDirecao()=="D") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(2));
                   else if(boss->getDirecao()=="C") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(1));
                   else if(boss->getDirecao()=="B") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(0));
                   else if(boss->getDirecao()=="E") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(3));
                   else if(boss->getDirecao()=="DID") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(4));
                   else if(boss->getDirecao()=="DIE") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(5));
                   else if(boss->getDirecao()=="DSD") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(6));
                   else if(boss->getDirecao()=="DSE") painter.drawImage(QRect(j*cw, i*ch, cw, ch), *boss->getImgMonstro(7));

                }
                else if(currentMap[i*cols+j]=='*')
                {
                    painter.drawImage(QRect(j*cw, i*ch, cw, ch), *gramaAux.getImgGround());
                    painter.drawImage(QRect(j*cw, i*ch, cw, ch), *player->getWeapon()->getFiring()->getImgAttack());
                }
                else painter.drawImage(QRect(j*cw, i*ch, cw, ch), *pedra.getImgStone());
            }
        }

        if(boss->getTimeReached().first)
        {
            painter.drawImage(QRect(boss->getPosicao().second*cw, boss->getPosicao().first*ch, cw, ch), *player->getWeapon()->getFiring()->getImgEndAttack());
            boss->playGrito();
        }


        actionBoss();
        update();
    }  catch (QString e) {
        QMessageBox::information(this,"ERRO",e);
    }
}

void IInterfaceJogo::administerShots()
{
    try
    {
         posiType x = player->getWeapon()->updateBulletPositions(currentMap,dD->getCols());
         if(player->getWeapon()->getFiring()->getQuantidade()==1)
         {
             currentMap[player->getWeapon()->getFiring()->getPosicao().first*dD->getCols()+player->getWeapon()->getFiring()->getPosicao().second]='*';
             tempMove(100,'f');
         }
         if(x.first.first!=-1)
         {
             if(x.second=='&')
             {
                 if(!boss->getTimeReached().first)
                      boss->setTimeReached({true,QTime::currentTime().addMSecs(200)});
                 player->getWeapon()->descarregar();
             }else if(x.second=='#')
             {
                 player->getWeapon()->descarregar();
             }
         }else
         {
             if(QTime::currentTime()>boss->getTimeReached().second)
             {
                 boss->setTimeReached({false,QTime::currentTime()});
             }
         }

    }  catch (QString erro) {
        QMessageBox::information(this,"erro",erro);
    }
}

void IInterfaceJogo::moverDireita()
{
    if(player->getMovementTime().first && collision.moveRight(player->getPosicao()))
    {
        player->playSomPassos();
        player->moverDireita();
        tempMove(player->getVelocidadeMovimento(),'p');
    }
    player->setDirecao("D");
    tempMove(0,'p');
    update();
}
void IInterfaceJogo::moverEsquerda()
{
    if(player->getMovementTime().first && collision.moveLeft(player->getPosicao()))
    {
        player->playSomPassos();
        player->moverEsquerda();
        tempMove(player->getVelocidadeMovimento(),'p');
    }
    player->setDirecao("E");
    tempMove(0,'p');
    update();
}
void IInterfaceJogo::moverCima()
{  
    if(player->getMovementTime().first && collision.moveUp(player->getPosicao()))
    {
        player->playSomPassos();
        player->moverCima();
        tempMove(player->getVelocidadeMovimento(),'p');
    }
    player->setDirecao("C");
    tempMove(0,'p');
    update();
}
void IInterfaceJogo::moverBaixo()
{    
    if(player->getMovementTime().first && collision.moveLow(player->getPosicao()))
    {
        player->playSomPassos();
        player->moverBaixo();
        tempMove(player->getVelocidadeMovimento(),'p');
    }

    player->setDirecao("B");
    tempMove(0,'p');
    update();
}

void IInterfaceJogo::quebrarDireita()
{
    if(collision.quebrarStoneRight(player->getPosicao()))pedra.playSomQuebrar();
}
void  IInterfaceJogo::quebrarEsquerda()
{
     if(collision.quebrarStoneLeft(player->getPosicao()))pedra.playSomQuebrar();
}
void  IInterfaceJogo::quebrarCima()
{
     if(collision.quebrarStoneUp(player->getPosicao()))pedra.playSomQuebrar();
}
void  IInterfaceJogo::quebrarBaixo()
{
     if(collision.quebrarStoneLow(player->getPosicao()))pedra.playSomQuebrar();
}

void IInterfaceJogo::criarDireita()
{
    if(collision.criarStoneRight(player->getPosicao()))pedra.playSomCriar();
}
void IInterfaceJogo::criarEsquerda()
{
    if(collision.criarStoneLeft(player->getPosicao()))pedra.playSomCriar();
}
void IInterfaceJogo::criarCima()
{
    if(collision.criarStoneUp(player->getPosicao()))pedra.playSomCriar();
}
void IInterfaceJogo::criarBaixo()
{
    if(collision.criarStoneLow(player->getPosicao()))pedra.playSomCriar();
}

int devolveId(pair<int, int> x, vector<Thing> list)
{
    for(int i=0; i<(int)list.size();i++)
        if(x==list[i].getPosicao())return list[i].getId();
    return -1;
}

void IInterfaceJogo::actionBoss()
{
    try
    {
        if(abs(player->getPosicao().first - boss->getPosicao().first) <= 5 && abs(player->getPosicao().second - boss->getPosicao().second) <= 5)
        {
            somMonstro[randomIndex()].play();

            if(boss->getMovementTime().first)
            {              
                int lins = dD->getLins();
                int cols = dD->getCols();
                int idCell=0;

                Bfs G(lins*cols);


                vector<Thing> shi;
                for(int i=0;i<lins; i++)
                {
                    for(int j=0; j<cols;j++)
                    {
                        if(currentMap[i*cols+j]!='#')
                        {
                            Thing cel({i,j},currentMap[i*cols+j],idCell++);
                            shi.push_back(cel);
                        }
                    }
                }

                for(int i=0;i<lins; i++)
                {
                    for(int j=0; j<cols;j++)
                    {
                        if(currentMap[i*cols+j]!='#')
                        {
                            if(collision.valida({i,j+1}))G.insereAresta(devolveId({i,j},shi),devolveId({i,j+1},shi));
                            if(collision.valida({i,j-1}))G.insereAresta(devolveId({i,j},shi),devolveId({i,j-1},shi));
                            if(collision.valida({i+1,j}))G.insereAresta(devolveId({i,j},shi),devolveId({i+1,j},shi));
                            if(collision.valida({i-1,j}))G.insereAresta(devolveId({i,j},shi),devolveId({i-1,j},shi));
                            if(collision.valida({i-1,j+1}) && currentMap[(i-1)*cols+(j+1)]!='#' && currentMap[(i-1)*cols+(j+1)]!='o')G.insereAresta(devolveId({i,j},shi),devolveId({i-1,j+1},shi));
                            if(collision.valida({i-1,j-1}) && currentMap[(i-1)*cols+(j-1)]!='#' && currentMap[(i-1)*cols+(j+1)]!='o')G.insereAresta(devolveId({i,j},shi),devolveId({i-1,j-1},shi));
                            if(collision.valida({i+1,j+1}) && currentMap[(i+1)*cols+(j+1)]!='#' && currentMap[(i-1)*cols+(j+1)]!='o')G.insereAresta(devolveId({i,j},shi),devolveId({i+1,j+1},shi));
                            if(collision.valida({i+1,j-1}) && currentMap[(i+1)*cols+(j-1)]!='#' && currentMap[(i-1)*cols+(j+1)]!='o')G.insereAresta(devolveId({i,j},shi),devolveId({i+1,j-1},shi));
                        }
                    }
                }

                int p[lins*cols], d[lins*cols];
                G.bfs(devolveId(boss->getPosicao(),shi),d,p);

                stack<int> percurso;
                int cont=0;
                for(int i=devolveId(player->getPosicao(),shi); i!=-1; i = p[i],cont++)
                    percurso.push(i);

                percurso.pop();

                if(shi[percurso.top()].getPosicao() != player->getPosicao())
                {
                    collision.pop(boss->getPosicao(),boss);

                    boss= new Monstro(shi[percurso.top()].getPosicao(),'&',0,dirBoss(shi[percurso.top()]),200,400);

                    collision.push(boss);
                    tempMove(boss->getVelocidadeMovimento(),'b');
                    update();
                }
            }
            tempMove(0,'b');
        }
    }  catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

QString IInterfaceJogo::dirBoss(Thing x)
{
    QString saida;
    pair<int, int> possBoss = boss->getPosicao(), possX = x.getPosicao();
    if(possBoss.first + 1 == possX.first)
    {
        if(possBoss.second + 1 == possX.second)
            saida="DID";
        else if(possBoss.second - 1 == possX.second)
            saida="DIE";
        else
            saida="B";
    }else if(possBoss.first - 1 == possX.first)
    {
        if(possBoss.second + 1 == possX.second)
            saida="DSD";
        else if(possBoss.second - 1 == possX.second)
            saida="DSE";
        else
            saida="C";
    }else if(possBoss.second + 1 == possX.second)
    {
        if(possBoss.first + 1 == possX.first)
            saida="DID";
        else if(possBoss.first - 1 == possX.first)
            saida="DSD";
        else
            saida="D";
    }else if(possBoss.second - 1 == possX.second)
    {
        if(possBoss.first + 1 == possX.first)
            saida="DIE";
        else if(possBoss.first - 1 == possX.first)
            saida="DSE";
        else
            saida="E";
    }
    return saida;
}

void IInterfaceJogo::tempMove(unsigned ms, char o)
{
    if(o=='p')
    {
        if(player->getMovementTime().first)
             player->setMovementTime({false,QTime::currentTime().addMSecs(ms)});
        else
        {
            if(QTime::currentTime()>player->getMovementTime().second)
                player->setMovementTime({true,QTime::currentTime()});
        }
    }else if(o=='b')
    {
        if(boss->getMovementTime().first)
             boss->setMovementTime({false,QTime::currentTime().addMSecs(ms)});
        else
        {
            if(QTime::currentTime()>boss->getMovementTime().second)
                boss->setMovementTime({true,QTime::currentTime()});
        }       
    }else if(o=='f')
    {
        if(player->getWeapon()->getFiring())
        {
            if(player->getWeapon()->getFiring()->getMovementTime().first)
                player->getWeapon()->getFiring()->setMovementTime({false,QTime::currentTime().addMSecs(ms)});
            else
            {
                if(QTime::currentTime()>player->getWeapon()->getFiring()->getMovementTime().second)
                    player->getWeapon()->getFiring()->setMovementTime({true,QTime::currentTime()});
            }
        }
    }
}

