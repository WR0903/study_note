#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->newButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())//单选框是否选上
    {
        this->hide();//屏幕隐藏
        this->timer=new QTimer;//新建定时器
        QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(shutScreenSlot()));
        this->timer->start(ui->spinBox->value()*1000);//启动定时器
    }
    else
    {
        qApp->beep();
        return;
    }
}
void MainWindow::shutScreenSlot()
{
    this->pixmap=QPixmap::grabWindow(QApplication::desktop()->winId());//获取当前屏幕的ID
    ui->label->setPixmap(this->pixmap.scaled(ui->label->size()));//在label上显示出来
    this->show();//屏幕显示
    this->timer->stop();//定时器停止
}
