#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QDateTime>
#include <QUrl>//打开网站
#include <QDesktopServices>//桌面服务的类
#include <about.h>
#include <QCloseEvent>//程序关闭，所有的成员函数都受到保护


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QString
protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QString saveFileName;
private slots:
    void newFileSlot();
    void openFileSlot();
    void saveFileSlot();
    void saveAsFileSlot();
    void setFontSlot();
    void setColorSlot();
    void currentTimeSlot();
    void aboutWebsiteSlot();
    void aboutSoftwareSlot();
};

#endif // MAINWINDOW_H
