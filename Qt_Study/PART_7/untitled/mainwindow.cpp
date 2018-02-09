#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(300,600);
    this->setMinimumSize(300,600);
    QObject::connect(ui->addButton,SIGNAL(clicked()),this,SLOT(addItemSlot()));
    QObject::connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteItemSlot()));
    QObject::connect(ui->cityLineEdit,SIGNAL(returnPressed()),this,SLOT(addItemSlot()));
    QObject::connect(ui->deleteAllButton,SIGNAL(clicked()),this,SLOT(deleteAllItemSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::addItemSlot()//添加项目
{
    QString cityName=ui->cityLineEdit->text();//从文本编辑器里面获得内容
    if(cityName.isEmpty())//判断是否为空
    {
        return;
    }
    QListWidgetItem *item=new QListWidgetItem;//新建项目
    item->setText(cityName);//设置项目内容
    ui->listWidget->addItem(item);//添加项目
    ui->cityLineEdit->clear();

}
void MainWindow::deleteItemSlot()
{
    QListWidgetItem *item=ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
}
void MainWindow::deleteAllItemSlot()
{
    int count=ui->listWidget->count();
    for(int index=0;index<count;index++)
    {
        QListWidgetItem *item=ui->listWidget->takeItem(0);
        delete item;
    }
}
