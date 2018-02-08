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
    QObject::connect(ui->saveAsAction,SIGNAL(triggered(bool)),this,SLOT(saveAsFileSlot()));
    QObject::connect(ui->saveAction,SIGNAL(triggered(bool)),this,SLOT(saveFileSlot()));
    QObject::connect(ui->exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
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
void MainWindow::saveFileSlot()
{
    if(saveFileName.isEmpty())
    {
        this->saveAsFileSlot();
    }
    QFile *file=new QFile;
    file->setFileName(saveFileName);
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);//使用out方法将文件和文件流相关联
        out<<ui->textEdit->toPlainText();//取出纯文本
        file->close();
        this->setWindowTitle(saveFileName);
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error","save file error"+file->errorString());
        return;
    }
}
void MainWindow::saveAsFileSlot()
{
    saveFileName=QFileDialog::getSaveFileName(this,"save file",QDir::currentPath());
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error","Please select a file;");
        return;
    }
    QFile *file=new QFile;
    file->setFileName(saveFileName);
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);//使用out方法将文件和文件流相关联
        out<<ui->textEdit->toPlainText();//取出纯文本
        file->close();
        this->setWindowTitle(saveFileName);
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error","save file error"+file->errorString());
        return;
    }
}
