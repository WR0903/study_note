#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <QImage>
#include <QTimer>
#include <QTime>
#include <string>
#include <QString>
#include <marderid.h>
#include <qcustomplot.h>

using namespace std;
extern double Visual_Eular[3];
extern double Visual_Position[3];



QImage cvMat2QImage(cv::Mat& mat);
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_openCameraButton_clicked();
    void readcamera_Frame();
    void on_closeCameraButton_clicked();

    void on_recordButton_clicked();

    void on_stopRecordButton_clicked();
    void writeVideo_Frame();
    void timerUpdate();
    void setupDisX_INIT();
    void setupDisY_INIT();
    void setupDisZ_INIT();
    void setupEularX_INIT();
    void setupEularY_INIT();
    void setupEularZ_INIT();
    void setupDisX();
    void setupDisY();
    void setupDisZ();
    void setupEularX();
    void setupEularY();
    void setupEularZ();
    void setupPlot();
private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture;
    cv::Mat camera_frame;
    QTimer *camera_timer;
    cv::VideoWriter createVideo;
    QTimer *video_timer;
    QTimer *timer_1;
    string timeStr;
    QString demoName;
    double num_x[101];
    double num_y[101];
    double num_z[101];
    double num_Ex[101];
    double num_Ey[101];
    double num_Ez[101];
};

#endif // MAINWINDOW_H
