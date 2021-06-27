#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QApplication>
#include<QMessageBox>
#include<QPainter>
#include<QImage>
#include<QInputDialog>
#include<iinterfacejogo.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::MainWindow *ui;
    IInterfaceJogo game;

    QImage *fundo;
    QPixmap *button;
    QIcon* bI;
    QMediaPlayer bip, inicio;


    andarDungeon * dDD;
    Tree collisionn;

    Jogador* playerr;
    Monstro* bosss;

};
#endif // MAINWINDOW_H
