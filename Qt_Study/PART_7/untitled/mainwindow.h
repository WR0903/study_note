#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QStringList>
#include <QListWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void addItemSlot();
    void deleteItemSlot();
    void deleteAllItemSlot();
    void showDirSlot();
    void singalSlot(QListWidgetItem *);
    void doubleSlot(QListWidgetItem *);
};

#endif // MAINWINDOW_H
