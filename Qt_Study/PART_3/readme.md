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
* 效果展示  
![](1.png)  

