#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer=new QTimer;
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(pixSlot()));
    this->timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pixSlot()
{
    QClipboard *clipboard = QApplication::clipboard();
    QPixmap originalPixmap = clipboard->pixmap();
    ui->label->setPixmap(originalPixmap.scaled(ui->label->size()));
}
