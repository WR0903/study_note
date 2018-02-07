#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->calButton,SIGNAL(clicked()),this,SLOT(calslot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calslot()
{
    int first=ui->firstLineEdit->text().toInt();
    int second=ui->secondLineEdit->text().toInt();
    int result=first+second;
    ui->valLineEdit->setText(QString::number(result));
}
