#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(300,600);
    this->setMinimumSize(300,600);
    ui->listWidget->setViewMode(QListView::IconMode);
    QObject::connect(ui->addButton,SIGNAL(clicked()),this,SLOT(addItemSlot()));
    QObject::connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteItemSlot()));
    QObject::connect(ui->cityLineEdit,SIGNAL(returnPressed()),this,SLOT(addItemSlot()));
    QObject::connect(ui->deleteAllButton,SIGNAL(clicked()),this,SLOT(deleteAllItemSlot()));
    QObject::connect(ui->showDirButton,SIGNAL(clicked(bool)),this,SLOT(showDirSlot()));
    QObject::connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(singalSlot(QListWidgetItem *)));
    QObject::connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(doubleSlot(QListWidgetItem *)));
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
void MainWindow::showDirSlot()
{
    QStringList fileNames=QFileDialog::getOpenFileNames(this,"open file",QDir::homePath());//可以获得多个文件
    if(fileNames.size()==0)//判断是否为空
    {
        QMessageBox::information(this,"Error","no file");
    }
    for(int i=0;i<fileNames.size();i++)
    {
        QListWidgetItem *item=new QListWidgetItem;
        item->setText(fileNames.at(i));
        ui->listWidget->addItem(item);
    }
}
void MainWindow::singalSlot(QListWidgetItem *item)
{
    QMessageBox::information(this,"information","signal"+item->text());
}
void MainWindow::doubleSlot(QListWidgetItem *item)
{
    QMessageBox::information(this,"information","double"+item->text());
}
