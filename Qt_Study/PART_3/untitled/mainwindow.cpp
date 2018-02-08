#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Untitle.txt");
    QObject::connect(ui->newAction,SIGNAL(triggered(bool)),this,SLOT(newFileSlot()));
    QObject::connect(ui->openAction,SIGNAL(triggered(bool)),this,SLOT(openFileSlot()));
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
void MainWindow::openFileSlot()
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open Files",QDir::currentPath());
    qDebug()<<"The file name is "<<fileName;
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error information","Please select a exit file;");
        return;
    }
    QFile *file=new QFile;
    file->setFileName(fileName);
    bool ok =file->open(QIODevice::ReadOnly);
    if(ok)
    {
        QTextStream in(file);//文件与文本流相关联
        ui->textEdit->setText(in.readAll());//读出当前文本的所有的内容
        file->close();//关掉file
        delete file;//释放file
    }
    else
    {
        QMessageBox::information(this,"Error","file open error"+file->errorString());
    }
}
