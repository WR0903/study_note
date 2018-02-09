# Qt_Study
* 获得文件属性
```
void MainWindow::getFileInfoSlot()//获取当前文件属性信息
{
    QString fileName=QFileDialog::getOpenFileName(this,"Open file",QDir::homePath());//文件打开对话框
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error","Please select a file;");
        return;
    }
    QFileInfo info(fileName);//info方法读取文件信息
    ui->sizeLineEdit->setText(QString::number(info.size()));//文件大小
    ui->timeLIneEdit->setText(info.created().toString("yyyy-M-d hh:mm:ss"));//读取文件创建时间,转换成string，按照一定的格式
    ui->lastTimeLineEdit->setText(info.lastRead().toString("yyyy-M-d hh:mm:ss"));//读取文件最后访问时间
    if(info.isDir())//查看是否为目录
    {
        ui->dirLineEdit->setText("Yes");
    }
    else
    {
        ui->dirLineEdit->setText("No");
    }

}
```
* 效果演示  

