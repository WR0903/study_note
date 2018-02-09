#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(600,250);
    this->setMinimumSize(600,250);
}

MainWindow::~MainWindow()
{
    delete ui;
}
