#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //对象实例化
    camera_timer=new QTimer(this);
    video_timer=new QTimer(this);
    timer_1=new QTimer(this);
    QTimer *timer=new QTimer(this);
    //界面的初始化
    ui->closeCameraButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->stopRecordButton->setEnabled(false);
    ui->visualPoseCheckBox->setCheckable(false);
    setupDisX_INIT();
    setupDisY_INIT();
    setupDisZ_INIT();
    setupEularX_INIT();
    setupEularY_INIT();
    setupEularZ_INIT();
    timer->start(1000);
    timer_1->start(100);


    QObject::connect(camera_timer,SIGNAL(timeout()),this,SLOT(readcamera_Frame()));
    QObject::connect(video_timer,SIGNAL(timeout()),this,SLOT(writeVideo_Frame()));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    QObject::connect(timer_1,SIGNAL(timeout()),this,SLOT(setupPlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openCameraButton_clicked()
{
    capture.open(0);
    camera_timer->start(50);
    ui->openCameraButton->setEnabled(false);
    ui->closeCameraButton->setEnabled(true);
    ui->recordButton->setEnabled(true);
    ui->visualPoseCheckBox->setCheckable(true);
    getCameraPose_init();
}
void MainWindow::readcamera_Frame()
{
    capture>>camera_frame;
    getCameraPose(camera_frame);
    QImage frame_out_show=cvMat2QImage(camera_frame);
    QImage frame_result_show=frame_out_show.scaled(ui->videoLabel->width(),ui->videoLabel->height());
    ui->videoLabel->setPixmap(QPixmap::fromImage(frame_result_show));
    if(ui->visualPoseCheckBox->isChecked())
    {
        ui->eulerXLineEdit->setText(QString::number(Visual_Eular[0]));
        ui->eulerYLineEdit->setText(QString::number(Visual_Eular[1]));
        ui->eulerZLineEdit->setText(QString::number(Visual_Eular[2]));
        ui->disXLineEdit->setText(QString::number(Visual_Position[0]));
        ui->disYLineEdit->setText(QString::number(Visual_Position[1]));
        ui->disZLineEdit->setText(QString::number(Visual_Position[2]));
    }
}
QImage cvMat2QImage(cv::Mat& mat)
{
    QImage* qimg=new QImage;
    *qimg = QImage((unsigned char*)mat.data, // uchar* data
            mat.cols, mat.rows, // width height
            QImage::Format_RGB888); //format
    return *qimg;
}

void MainWindow::on_closeCameraButton_clicked()
{
    camera_timer->stop();
    capture.release();
    ui->videoLabel->clear();
    ui->openCameraButton->setEnabled(true);
    ui->closeCameraButton->setEnabled(false);
    ui->recordButton->setEnabled(false);
    ui->visualPoseCheckBox->setCheckable(false);
}

void MainWindow::on_recordButton_clicked()
{
    string srN="1.avi";
    string srC=timeStr+srN;
    createVideo.open(srC,CV_FOURCC('M', 'J', 'P', 'G'),25.0,cv::Size(camera_frame.cols,camera_frame.rows));
    cout<<"record video"<<endl;
    ui->stopRecordButton->setEnabled(true);
    ui->recordButton->setEnabled(false);
    ui->closeCameraButton->setEnabled(false);
    video_timer->start(40);
}
void MainWindow::writeVideo_Frame()
{
    createVideo<<camera_frame;
}
void MainWindow::on_stopRecordButton_clicked()
{
    video_timer->stop();
    ui->closeCameraButton->setEnabled(true);
    ui->stopRecordButton->setEnabled(false);
    ui->recordButton->setEnabled(true);
}
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str=time.toString("yyyy-MM-dd hh::mm::ss");
    timeStr=str.toStdString();//QString to String
    ui->realTimeLabel->setText(str);

}
void MainWindow::setupDisX_INIT()
{
    demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->disXWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->disXWidget->setBackground(qBrush);
    //ui->disXWidget->legend->setVisible(true);
    ui->disXWidget->addGraph();
    ui->disXWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->disXWidget->xAxis->setLabel("x");
    ui->disXWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->disXWidget->xAxis->setRange(0,101);
    ui->disXWidget->yAxis->setRange(-250,250);
    ui->disXWidget->xAxis->setTicks(true);//设置刻度使能
    ui->disXWidget->yAxis->setTicks(true);
    setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupEularX_INIT()
{
    demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->eularXWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->eularXWidget->setBackground(qBrush);
    //ui->eularXWidget->legend->setVisible(true);
    ui->eularXWidget->addGraph();
    ui->eularXWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->eularXWidget->xAxis->setLabel("x");
    ui->eularXWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->eularXWidget->xAxis->setRange(0,101);
    ui->eularXWidget->yAxis->setRange(-90,90);
    ui->eularXWidget->xAxis->setTicks(true);//设置刻度使能
    ui->eularXWidget->yAxis->setTicks(true);
    setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupDisY_INIT()
{
   // demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->disYWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->disYWidget->setBackground(qBrush);
    //ui->disYWidget->legend->setVisible(true);
    ui->disYWidget->addGraph();
    ui->disYWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->disYWidget->xAxis->setLabel("x");
    ui->disYWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->disYWidget->xAxis->setRange(0,101);
    ui->disYWidget->yAxis->setRange(-250,250);
    ui->disYWidget->xAxis->setTicks(true);//设置刻度使能
    ui->disYWidget->yAxis->setTicks(true);
    //setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupEularY_INIT()
{
    demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->eularYWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->eularYWidget->setBackground(qBrush);
    //ui->eularXWidget->legend->setVisible(true);
    ui->eularYWidget->addGraph();
    ui->eularYWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->eularYWidget->xAxis->setLabel("x");
    ui->eularYWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->eularYWidget->xAxis->setRange(0,101);
    ui->eularYWidget->yAxis->setRange(-180,180);
    ui->eularYWidget->xAxis->setTicks(true);//设置刻度使能
    ui->eularYWidget->yAxis->setTicks(true);
    setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupDisZ_INIT()
{
   // demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->disZWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->disZWidget->setBackground(qBrush);
    //ui->disZWidget->legend->setVisible(true);
    ui->disZWidget->addGraph();
    ui->disZWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->disZWidget->xAxis->setLabel("x");
    ui->disZWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->disZWidget->xAxis->setRange(0,101);
    ui->disZWidget->yAxis->setRange(0,1250);
    ui->disZWidget->xAxis->setTicks(true);//设置刻度使能
    ui->disZWidget->yAxis->setTicks(true);
    //setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupEularZ_INIT()
{
    demoName = "Quadratic Demo";
    // generate some data:

    // create graph and assign data to it:
    ui->eularZWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(255,255,255));// 背景颜色
    ui->eularZWidget->setBackground(qBrush);
    //ui->eularXWidget->legend->setVisible(true);
    ui->eularZWidget->addGraph();
    ui->eularZWidget->graph(0)->setPen(QPen(Qt::red));

    // give the axes some labels:
    ui->eularZWidget->xAxis->setLabel("x");
    ui->eularZWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->eularZWidget->xAxis->setRange(0,101);
    ui->eularZWidget->yAxis->setRange(-180,180);
    ui->eularZWidget->xAxis->setTicks(true);//设置刻度使能
    ui->eularZWidget->yAxis->setTicks(true);
    setWindowTitle("QCustomPlot: "+demoName);

}
void MainWindow::setupDisX()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_x[i]=num_x[i+1];
    }
    num_x[100]=Visual_Position[0];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_x[i];  // let's plot a quadratic function
    }
    ui->disXWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->disXWidget->replot();
}
void MainWindow::setupDisY()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_y[i]=num_y[i+1];
    }
    num_y[100]=Visual_Position[1];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_y[i];  // let's plot a quadratic function
    }
    ui->disYWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->disYWidget->replot();
}
void MainWindow::setupDisZ()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_z[i]=num_z[i+1];
    }
    num_z[100]=Visual_Position[2];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_z[i];  // let's plot a quadratic function
    }
    ui->disZWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->disZWidget->replot();
}
void MainWindow::setupEularX()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_Ex[i]=num_Ex[i+1];
    }
    num_Ex[100]=Visual_Eular[0];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_Ex[i];  // let's plot a quadratic function
    }
    ui->eularXWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->eularXWidget->replot();
}
void MainWindow::setupEularY()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_Ey[i]=num_Ey[i+1];
    }
    num_Ey[100]=Visual_Eular[1];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_Ey[i];  // let's plot a quadratic function
    }
    ui->eularYWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->eularYWidget->replot();
}
void MainWindow::setupEularZ()
{
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for(int i=0;i<100;i++)
    {
        num_Ez[i]=num_Ez[i+1];
    }
    num_Ez[100]=Visual_Eular[2];
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = num_Ez[i];  // let's plot a quadratic function
    }
    ui->eularZWidget->graph(0)->setData(x,y);
    statusBar()->clearMessage();
    ui->eularZWidget->replot();
}
void MainWindow::setupPlot()
{
    setupDisX();
    setupDisY();
    setupDisZ();
    setupEularX();
    setupEularY();
    setupEularZ();
}
