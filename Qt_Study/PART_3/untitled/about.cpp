#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->Movie=new QMovie("1.gif");
    ui->movieLable->setMovie(this->Movie);
    qDebug()<<"The movie has frame:"<<Movie->frameCount();
    //this->Movie->start();
    QObject::connect(ui->helloButton,SIGNAL(clicked(bool)),this,SLOT(startMovieSlot()));
    QObject::connect(ui->noButton,SIGNAL(clicked(bool)),this,SLOT(stopMovieSlot()));
}
about::~about()
{
    delete ui;
}
void about::startMovieSlot()
{
    this->Movie->start();
}
void about::stopMovieSlot()
{
    this->Movie->stop();
}
