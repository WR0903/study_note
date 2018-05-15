#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <pthread.h>

using namespace std;
using namespace cv;

//QString str;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void duqu();
    //void *thread1(void *ptr);
private:
    Ui::MainWindow *ui;
    QTimer *time1;
    QString a;
    //QFile file;
private slots:
    void uplable();

};

#endif // MAINWINDOW_H
