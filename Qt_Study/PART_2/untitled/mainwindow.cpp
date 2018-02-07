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
    int result;
    if(ui->comboBox->currentIndex()==0)
    {
        result=first+second;
        ui->valLineEdit->setText(QString::number(result));
    }
    if(ui->comboBox->currentIndex()==1)
    {
        result=first-second;
        ui->valLineEdit->setText(QString::number(result));
    }
    if(ui->comboBox->currentIndex()==2)
    {
        result=first*second;
        ui->valLineEdit->setText(QString::number(result));
    }
    if(ui->comboBox->currentIndex()==3)
    {
        if(second==0)
        {
            QMessageBox::warning(this,"WARNING","Second can't be zero");
            ui->firstLineEdit->clear();
            ui->secondLineEdit->clear();
            return;
        }
        result=first/second;
        ui->valLineEdit->setText(QString::number(result));
    }
    QMessageBox::information(this,"RESULT",QString::number(result));
    ui->firstLineEdit->clear();
    ui->secondLineEdit->clear();
    ui->valLineEdit->clear();
}
