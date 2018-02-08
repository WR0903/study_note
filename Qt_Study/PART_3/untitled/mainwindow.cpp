#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitle.txt");
    QObject::connect(ui->newAction,SIGNAL(triggered(bool)),this,SLOT(newFileSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newFileSlot()
{
    if(ui->textEdit->document()->isModified())
    {
        qDebug()<<"The current file is modified.";
    }
    else
    {
        qDebug()<<"no";
        ui->textEdit->clear();
        this->setWindowTitle("Untitled.txt");
    }
}
