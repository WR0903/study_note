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
    void demo_init();
    void demo_widget1();
    void demo_widget2();
    void demo_widget3();
    void demo_widget0();
    void demo_widget4();
    void demo_widget5();

private:
    Ui::MainWindow *ui;
private slots:
    void mouseWheel();
    void selectionChanged();
    
};

#endif // MAINWINDOW_H
