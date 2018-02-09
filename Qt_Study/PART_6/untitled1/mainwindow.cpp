#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(600,250);
    this->setMinimumSize(600,250);
    QObject::connect(ui->openFileButton,SIGNAL(clicked()),this,SLOT(getFileInfoSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getFileInfoSlot()//获取当前文件属性信息
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open file",QDir::homePath());
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error","Please select a file;");
        return;
    }
    QFileInfo info(fileName);
    ui->sizeLineEdit->setText(QString::number(info.size()));
    ui->timeLIneEdit->setText(info.created().toString("yyyy-M-d hh:mm:ss"));//转换成string，按照一定的格式
    ui->lastTimeLineEdit->setText(info.lastRead().toString("yyyy-M-d hh:mm:ss"));
    if(info.isDir())
    {
        ui->dirLineEdit->setText("Yes");
    }
    else
    {
        ui->dirLineEdit->setText("No");
    }

}
