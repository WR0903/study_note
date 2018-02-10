#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDesktopServices>//StorageLocation
#include <QFileDialog>
#include <QClipboard>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QProcess>
//#include <QChick>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void contextMenuEvent(QContextMenuEvent *Event);

private slots:
    void on_pushButton_clicked();
    void shutScreenSlot();
    void savePictureSlot();
    void startGeditSlot();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap pixmap;
};

#endif // MAINWINDOW_H
