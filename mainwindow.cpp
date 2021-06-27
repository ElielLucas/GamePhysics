#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButtonStart->setIcon(QIcon("C:/ArquivosGamePhysics/release/button.png"));
    ui->pushButtonStart->setIconSize(QSize(181,61));
    fundo = new QImage("C:/ArquivosGamePhysics/release/imgFundoInicial.png");
    bip.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/bip.mp3"));
    inicio.setMedia(QUrl::fromLocalFile("C:/ArquivosGamePhysics/release/inicio.mp3"));
    bip.play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(600);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    try
    {
        int w= width();
        int h= height();

        int cw=w/10;
        int ch=h/10;
        QPainter painter(this);

        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
               painter.drawImage(QRect(j*cw, i*ch, cw, ch), *fundo);

    }  catch (QString e) {
        QMessageBox::information(this,"ERRO",e);
    }
}
void MainWindow::on_pushButtonStart_clicked()
{
    inicio.play();
    delay();
    game.exec();
}
