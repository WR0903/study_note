#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passewordLineEdit->setEchoMode(QLineEdit::Password);
    this->setMaximumSize(393,197);
    this->setMinimumSize(393,197);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->usrLineEdit->text()=="1"&&ui->passewordLineEdit->text()=="1")
    {
        QMessageBox::information(this,"congratulation","登陆。。。");
    }
    else
    {
        QMessageBox::information(this,"Error","请输入正确的帐号和密码");
        return;
    }
}
