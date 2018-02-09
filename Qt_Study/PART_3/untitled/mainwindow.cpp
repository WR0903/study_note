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

    QObject::connect(ui->undoAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(undo()));
    QObject::connect(ui->redoAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(redo()));
    QObject::connect(ui->copyAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(copy()));
    QObject::connect(ui->pasteAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(paste()));
    QObject::connect(ui->cutAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(cut()));
    QObject::connect(ui->selectAllAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(selectAll()));
    QObject::connect(ui->fontAction,SIGNAL(triggered(bool)),this,SLOT(setFontSlot()));
    QObject::connect(ui->colorAction,SIGNAL(triggered(bool)),this,SLOT(setColorSlot()));
    QObject::connect(ui->dateTimeAction,SIGNAL(triggered(bool)),this,SLOT(currentTimeSlot()));
    QObject::connect(ui->aboutQtAction,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    QObject::connect(ui->aboutWebAction,SIGNAL(triggered(bool)),this,SLOT(aboutWebsiteSlot()));
    QObject::connect(ui->aboutSoftWareAction,SIGNAL(triggered(bool)),this,SLOT(aboutSoftwareSlot()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->textEdit->document()->isModified())
    {

  QMessageBox msgBox;
  msgBox.setText("The document has been modified.");
  //显示的文本
  msgBox.setInformativeText("Do you want to save your changes?");
  //需要你做的操作
  msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  //三个按钮
  msgBox.setDefaultButton(QMessageBox::Save);
  //默认的按钮
  int ret = msgBox.exec();//对话框关闭的时候返回你操作的结果
  switch (ret) {
      case QMessageBox::Save:
          // Save was clicked
          this->saveFileSlot();
          break;
      case QMessageBox::Discard:
          // Don't Save was clicked
          event->accept();
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
          event->ignore();
          break;
      default:
          // should never be reached
          event->ignore();
          break;
    }

    }
    else
    {
        event->accept();
    }
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
void MainWindow::setFontSlot()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"Error","please select a font;");
        return;
    }
}
void MainWindow::setColorSlot()
{
    QColor color=QColorDialog::getColor(Qt::red,this);
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
    else
    {
        QMessageBox::information(this,"Error","Error set color");
        return;
    }
}
void MainWindow::currentTimeSlot()
{
    QDateTime current=QDateTime::currentDateTime();//获得当前的时间
    QString time=current.toString("yyyy-M-d hh:mm:ss");//转换成string，按照一定的格式
    ui->textEdit->append(time);//在末尾追加
}
void MainWindow::aboutWebsiteSlot()//使用的是默认浏览器
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}
void MainWindow::aboutSoftwareSlot()//弹出子对话框
{
    about *dialog=new about;
    dialog->show();
}
