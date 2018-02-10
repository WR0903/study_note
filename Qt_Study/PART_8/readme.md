# Qt_Study
* Widget和MainWindow的区别：
Widget没有菜单栏，MainWindow有菜单栏
* 常用类的用法  
```
int first=ui->firstLineEdit->text().toInt();//取第一个文本编辑器的值，并转换成int类型  
int second=ui->secondLineEdit->text().toInt();//取第二个文本编辑器的值，并转换成int类型  
int result=first+second;  
ui->valLineEdit->setText(QString::number(result));//把结果在第三个文本编辑器里面显示出来，用setText方法，并且需要转换成string类型  
```


`ui->comboBox->currentIndex();//返回下拉框的索引值`

```
QMessageBox::warning(this,"WARNING","Second can't be zero");//警告对话框
QMessageBox::information(this,"RESULT",QString::number(result));//信息对话框
```

`qDebug()<<"The current file is modified.";//Qt自带的调试打印，需要添加#include <QtDebug>`  
action的一个常用信号：triggered(bool)；表示这个action被按下。  
`this->setWindowTitle("Untitle.txt");//设置窗口的标题，这里不用ui，我的理解是ui是界面内，this表示这个界面`  
* 打开一个文件的操作
```
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
    QString fileName=QFileDialog::getOpenFileName(this,"Open Files",QDir::currentPath());//用对话框打开当前目录下的文件
    qDebug()<<"The file name is "<<fileName;//调试打印信息，文件的名称
    if(fileName.isEmpty())//如果没有打开
    {
        QMessageBox::information(this,"Error information","Please select a exit file;");//用QMessageBox对话框打印错误信息
        return;
    }
    QFile *file=new QFile;//新建一个file
    file->setFileName(fileName);//设置文件名称
    bool ok =file->open(QIODevice::ReadOnly);//open方法打开file，并设置权限为readonly
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
```
* 保存文件的操作
```
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
    saveFileName=QFileDialog::getSaveFileName(this,"save file",QDir::currentPath());//弹出对话框，选择保存文件的位置和名字
    if(saveFileName.isEmpty())
    {
        QMessageBox::information(this,"Error","Please select a file;");
        return;
    }
    QFile *file=new QFile;//新建文件
    file->setFileName(saveFileName);//设置文件名字
    bool ok=file->open(QIODevice::WriteOnly);//open方法打开文件，并设置权限为只写
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
```
* 设置颜色和字体
```
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
void MainWindow::setFontSlot()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);//从字体对话框获取字体
    if(ok)//ok判断获取是否成功
    {
        ui->textEdit->setFont(font);//对文本编辑器里选中的字体进行设置
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

```
* 关于编辑常用的槽函数
```
QObject::connect(ui->undoAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(undo()));
QObject::connect(ui->redoAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(redo()));
QObject::connect(ui->copyAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(copy()));
QObject::connect(ui->pasteAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(paste()));
QObject::connect(ui->cutAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(cut()));
QObject::connect(ui->selectAllAction,SIGNAL(triggered(bool)),ui->textEdit,SLOT(selectAll()));
```
* 获得时间的方法
```
void MainWindow::currentTimeSlot()
{
    QDateTime current=QDateTime::currentDateTime();//获得当前的时间
    QString time=current.toString("yyyy-M-d hh:mm:ss");//转换成string，按照一定的格式
    ui->textEdit->append(time);//在末尾追加
}
```
* 关闭事件处理
```
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
```
* 截图的实现,并保存图片
```
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
    QClipboard *clipboard = QApplication::clipboard();//新建剪切板
    //QPixmap originalPixmap = clipboard->pixmap();

    clipboard->setPixmap(this->pixmap);//把截得的图片放在剪切板上
    this->show();//屏幕显示
    this->timer->stop();//定时器停止
}
void MainWindow::savePictureSlot()
{
    QString fileName=QFileDialog::getSaveFileName(this,"save file",QDesktopServices::storageLocation(QDesktopServices::PicturesLocation));

    this->pixmap.save(fileName);//保存图片
}
```
* 两个程序之间通过剪切板通信
上面的截图的实现是发送端,一下是接收端  
```
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer=new QTimer;//新建定时器
    QObject::connect(this->timer,SIGNAL(timeout()),this,SLOT(pixSlot()));
    this->timer->start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pixSlot()
{
    QClipboard *clipboard = QApplication::clipboard();//新建剪切板
    QPixmap originalPixmap = clipboard->pixmap();//从剪切板取出图片
    ui->label->setPixmap(originalPixmap.scaled(ui->label->size()));//播放
}

```
* 右击菜单
```
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
```
* 效果展示  
![](1.png)  
