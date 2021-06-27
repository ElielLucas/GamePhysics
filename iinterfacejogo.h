#ifndef IINTERFACEJOGO_H
#define IINTERFACEJOGO_H

#include<QPainter>
#include<QImage>
#include <QDialog>
#include<QMessageBox>
#include<QTime>
#include<QInputDialog>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QMediaPlayer>

#include<andardungeon.h>
#include<treeavl.h>
#include<jogador.h>
#include<monstro.h>
#include<stone.h>
#include<ground.h>
#include<bfs.h>
#include<list.h>
#include<stack.h>



namespace Ui {
class IInterfaceJogo;
}

class IInterfaceJogo : public QDialog
{
    Q_OBJECT

public:
    andarDungeon * dD;
    Tree collision;

    QMediaPlayer somAmbiente;
    QMediaPlayer* somMonstro;

    Jogador* player;
    Monstro* boss;   

    Stone pedra;
    Ground gramaAux;

    QString currentMap;

    explicit IInterfaceJogo(QWidget *parent = nullptr);
    ~IInterfaceJogo();

private slots:

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void moverDireita();
    void moverEsquerda();
    void moverCima();
    void moverBaixo();

    void quebrarDireita();
    void quebrarEsquerda();
    void quebrarCima();
    void quebrarBaixo();

    void criarDireita();
    void criarEsquerda();
    void criarCima();
    void criarBaixo();

    void administerShots();

    void actionBoss();
    QString dirBoss(Thing x);

    void tempMove(unsigned ms, char o);
    int randomIndex(){return (rand() % 4);}


private:
    Ui::IInterfaceJogo *ui;

};

#endif // IINTERFACEJOGO_H
