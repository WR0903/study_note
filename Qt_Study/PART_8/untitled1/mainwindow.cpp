#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->newButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    QObject::connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(savePictureSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::contextMenuEvent(QContextMenuEvent *Event)
{
    QMenu *menu=new QMenu(this);//右击出现菜单
    QAction *action=new QAction(this);//菜单的每一项
    QAction *process=new QAction(this);
    action->setText("save as");//每一项的名称
    process->setText("process");
    QObject::connect(process,SIGNAL(triggered(bool)),this,SLOT(startGeditSlot()));
    QObject::connect(action,SIGNAL(triggered(bool)),this,SLOT(savePictureSlot()));
    menu->addAction(process);
    menu->addAction(action);//将该项添加在菜单中
    menu->exec(QCursor::pos());//菜单启动运行,出现的位置是鼠标的位置
}
void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())//单选框是否选上
    {
        this->hide();//屏幕隐藏
        this->timer=new QTimer;//新建定时器
        QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(shutScreenSlot()));
        this->timer->start(ui->spinBox->value()*1000);//启动定时器
    }
    else
    {
        qApp->beep();
        return;
    }
}
void MainWindow::shutScreenSlot()
{
    this->pixmap=QPixmap::grabWindow(QApplication::desktop()->winId());//获取当前屏幕的ID
    ui->label->setPixmap(this->pixmap.scaled(ui->label->size()));//在label上显示出来
    QClipboard *clipboard = QApplication::clipboard();
    //QPixmap originalPixmap = clipboard->pixmap();

    clipboard->setPixmap(this->pixmap);
    this->show();//屏幕显示
    this->timer->stop();//定时器停止
}
void MainWindow::savePictureSlot()
{
    QString fileName=QFileDialog::getSaveFileName(this,"save file",QDesktopServices::storageLocation(QDesktopServices::PicturesLocation));

    this->pixmap.save(fileName);
}
void MainWindow::startGeditSlot()
{
    QProcess *process=new QProcess;
    process->start("gedit");
}
