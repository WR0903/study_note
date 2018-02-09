#include <QCoreApplication>
#include <QDir>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<"the home path is"<<QDir::homePath();//home目录
    qDebug()<<"the root path is"<<QDir::rootPath();//根目录
    qDebug()<<"the temp path is"<<QDir::tempPath();//临时文件目录
    return a.exec();
}
