#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <qcustomplot.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void demo1();
    void demo2();
    void demo3();
    void demo4();
    void demo5();

private:
    Ui::MainWindow *ui;
private slots:
    void mouseWheel();
    void selectionChanged();
    
};

#endif // MAINWINDOW_H
