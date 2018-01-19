#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    demo_init();//所有窗口的初始化
    demo_widget1();
    demo_widget2();
    demo_widget3();
    demo_widget0();
    demo_widget4();
    demo_widget5();
    demo_widget6();
    demo_widget7();
    demo_widget8();
    connect(ui->qcustomplotWidget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));//连接鼠标点击信号和槽
    connect(ui->qcustomplotWidget, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));//连接鼠标滚轮信号和槽
      //  connect(ui->qcustomplotWidget, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));//连接曲线选择信号和槽

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::demo_init()//所有窗口的初始化
{
    //第一个窗口的初始化
    ui->qcustomplotWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(0,255,255));// 背景颜色
    ui->qcustomplotWidget->setBackground(qBrush);
    ui->qcustomplotWidget->legend->setVisible(true);

    ui->qcustomplotWidget->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget->xAxis->setRange(0.0,5.0);//数值范围

    ui->qcustomplotWidget->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget->yAxis->setSubTicks(true);
    ui->qcustomplotWidget->yAxis->setRange(-1,1.0);//数值范围
    //第二个窗口的初始化
    ui->qcustomplotWidget_1->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush1(QColor(255,0,255));// 背景颜色
    ui->qcustomplotWidget_1->setBackground(qBrush1);
    ui->qcustomplotWidget_1->legend->setVisible(true);

    ui->qcustomplotWidget_1->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_1->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_1->xAxis->setRange(0.0,5.0);//数值范围

    ui->qcustomplotWidget_1->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_1->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_1->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_1->yAxis->setRange(-1,1.0);//数值范围

    //第三个窗口的初始化
    ui->qcustomplotWidget_2->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush2(QColor(255,255,0));// 背景颜色
    ui->qcustomplotWidget_2->setBackground(qBrush2);
    ui->qcustomplotWidget_2->legend->setVisible(true);

    ui->qcustomplotWidget_2->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_2->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_2->xAxis->setRange(0.0,255.0);//数值范围

    ui->qcustomplotWidget_2->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_2->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_2->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_2->yAxis->setRange(-1,1.0);//数值范围
    //第四个窗口的初始化
    ui->qcustomplotWidget_3->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush3(QColor(0,0,255));// 背景颜色
    ui->qcustomplotWidget_3->setBackground(qBrush3);
    ui->qcustomplotWidget_3->legend->setVisible(true);

    ui->qcustomplotWidget_3->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_3->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_3->xAxis->setRange(0.0,255.0);//数值范围

    ui->qcustomplotWidget_3->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_3->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_3->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_3->yAxis->setRange(-1,1.0);//数值范围

    //第五个窗口的初始化
    ui->qcustomplotWidget_4->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush4(QColor(0,255,0));// 背景颜色
    ui->qcustomplotWidget_4->setBackground(qBrush4);
    ui->qcustomplotWidget_4->legend->setVisible(true);

    ui->qcustomplotWidget_4->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_4->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_4->xAxis->setRange(0.0,15.0);//数值范围

    ui->qcustomplotWidget_4->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_4->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_4->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_4->yAxis->setRange(-1,1.0);//数值范围

    //第六个窗口的初始化
    ui->qcustomplotWidget_5->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush5(QColor(255,0,0));// 背景颜色
    ui->qcustomplotWidget_5->setBackground(qBrush5);
    ui->qcustomplotWidget_5->legend->setVisible(true);

    ui->qcustomplotWidget_5->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_5->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_5->xAxis->setRange(0.0,15.0);//数值范围

    ui->qcustomplotWidget_5->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_5->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_5->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_5->yAxis->setRange(-1,1.0);//数值范围

    //第七个窗口的初始化
    ui->qcustomplotWidget_6->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush6(QColor(100,200,100));// 背景颜色
    ui->qcustomplotWidget_6->setBackground(qBrush6);
    ui->qcustomplotWidget_6->legend->setVisible(true);

    ui->qcustomplotWidget_6->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_6->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_6->xAxis->setRange(0.0,15.0);//数值范围

    ui->qcustomplotWidget_6->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_6->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_6->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_6->yAxis->setRange(-1,1.0);//数值范围

    //第八个窗口的初始化
    ui->qcustomplotWidget_7->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush7(QColor(150,50,50));// 背景颜色
    ui->qcustomplotWidget_7->setBackground(qBrush7);
    ui->qcustomplotWidget_7->legend->setVisible(true);

    ui->qcustomplotWidget_7->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_7->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_7->xAxis->setRange(0.0,15.0);//数值范围

    ui->qcustomplotWidget_7->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_7->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_7->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_7->yAxis->setRange(-1,1.0);//数值范围

    //第九个窗口的初始化
    ui->qcustomplotWidget_8->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush8(QColor(200,100,100));// 背景颜色
    ui->qcustomplotWidget_8->setBackground(qBrush8);
    ui->qcustomplotWidget_8->legend->setVisible(true);

    ui->qcustomplotWidget_8->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget_8->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget_8->xAxis->setRange(0.0,15.0);//数值范围

    ui->qcustomplotWidget_8->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget_8->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget_8->yAxis->setSubTicks(true);
    ui->qcustomplotWidget_8->yAxis->setRange(-1,1.0);//数值范围
}

void MainWindow::demo_widget1()//普通的曲线
{
    QVector<double>x(251),y(251);
    for(int i=0;i<251;++i)
    {
        x[i]=i;
        y[i]=qCos(i/10.0);
    }
    ui->qcustomplotWidget_1->addGraph();//添加一个图层
    ui->qcustomplotWidget_1->graph(0)->setPen(QPen(Qt::red));//将线条颜色设置为蓝色
    ui->qcustomplotWidget_1->graph(0)->setData(x,y);//在这个图层添加数据
    ui->qcustomplotWidget_1->xAxis->setLabel("x");//设置x轴
    ui->qcustomplotWidget_1->yAxis->setLabel("y");//设置y轴
    ui->qcustomplotWidget_1->xAxis->setRange(0,255);//设置x轴的范围
    ui->qcustomplotWidget_1->yAxis->setRange(-1,1);//设置y轴的范围
}
void MainWindow::demo_widget2()//普通曲线下方的阴影
{
    ui->qcustomplotWidget_2->addGraph();//添加一个图层
    ui->qcustomplotWidget_2->graph(0)->setPen(QPen(Qt::blue));//将线条颜色设置为蓝色
    ui->qcustomplotWidget_2->graph(0)->setBrush(QBrush(QColor(0,0,255,200)));//曲线下面的阴影//前3个参数是颜色，第四个参数是透明度
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    ui->qcustomplotWidget_2->graph(0)->setData(x, y0);
    ui->qcustomplotWidget_2->xAxis2->setVisible(true);
    ui->qcustomplotWidget_2->xAxis2->setTickLabels(false);
    ui->qcustomplotWidget_2->yAxis2->setVisible(true);
    ui->qcustomplotWidget_2->yAxis2->setTickLabels(false);

}
void MainWindow::demo_widget3()
{
    ui->qcustomplotWidget_3->legend->setVisible(true);//可见
    ui->qcustomplotWidget_3->legend->setFont(QFont("Helvetica",9));//字体
    ui->qcustomplotWidget_3->setLocale(QLocale(QLocale::English,QLocale::UnitedKingdom));
    ui->qcustomplotWidget_3->addGraph();//添加一个图层
    QPen pen;
    pen.setStyle(Qt::DotLine);//点线
    pen.setWidth(1);//线宽
    pen.setColor(QColor(180,180,180));//颜色
    ui->qcustomplotWidget_3->graph(0)->setName("Confidence Band 68%");//图层名称
    ui->qcustomplotWidget_3->graph(0)->setPen(pen);
    ui->qcustomplotWidget_3->graph(0)->setBrush(QBrush(QColor(255,50,30,20)));//线下面的阴影
    ui->qcustomplotWidget_3->addGraph();//添加一个图层
    ui->qcustomplotWidget_3->legend->removeItem(ui->qcustomplotWidget_3->legend->itemCount()-1); // 不要在图例中显示两个置信带图
    ui->qcustomplotWidget_3->graph(1)->setPen(pen);
    ui->qcustomplotWidget_3->graph(0)->setChannelFillGraph(ui->qcustomplotWidget_3->graph(1));
    ui->qcustomplotWidget_3->addGraph();
    pen.setStyle(Qt::DashLine);//虚线
    pen.setWidth(2);//线宽
    pen.setColor(Qt::red);//红色
    ui->qcustomplotWidget_3->graph(2)->setPen(pen);
    ui->qcustomplotWidget_3->graph(2)->setName("Theory Curve");
    ui->qcustomplotWidget_3->addGraph();
    ui->qcustomplotWidget_3->graph(3)->setPen(QPen(Qt::blue));
    ui->qcustomplotWidget_3->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->qcustomplotWidget_3->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
    QCPErrorBars *errorBars = new QCPErrorBars(ui->qcustomplotWidget_3->xAxis, ui->qcustomplotWidget_3->yAxis);
    errorBars->removeFromLegend();
    errorBars->setAntialiased(false);
    errorBars->setDataPlottable(ui->qcustomplotWidget_3->graph(1));
    errorBars->setPen(QPen(QColor(180,180,180)));
    ui->qcustomplotWidget_3->graph(3)->setName("Measurement");
    QVector<double> x0(250), y0(250);
    QVector<double> yConfUpper(250), yConfLower(250);
    for (int i=0; i<250; ++i)
    {
      x0[i] = (i/249.0-0.5)*30+0.01; // by adding a small offset we make sure not do divide by zero in next code line
      y0[i] = qSin(x0[i])/x0[i]; // sinc function
      yConfUpper[i] = y0[i]+0.15;
      yConfLower[i] = y0[i]-0.15;
      x0[i] *= 1000;
    }
    QVector<double> x1(50), y1(50), y1err(50);
    for (int i=0; i<50; ++i)
    {
      // generate a gaussian distributed random number:
      double tmp1 = rand()/(double)RAND_MAX;
      double tmp2 = rand()/(double)RAND_MAX;
      double r = qSqrt(-2*qLn(tmp1))*qCos(2*M_PI*tmp2); // box-muller transform for gaussian distribution
      // set y1 to value of y0 plus a random gaussian pertubation:
      x1[i] = (i/50.0-0.5)*30+0.25;
      y1[i] = qSin(x1[i])/x1[i]+r*0.15;
      x1[i] *= 1000;
      y1err[i] = 0.15;
    }
    ui->qcustomplotWidget_3->graph(0)->setData(x0, yConfUpper);
    ui->qcustomplotWidget_3->graph(1)->setData(x0, yConfLower);
    ui->qcustomplotWidget_3->graph(2)->setData(x0, y0);
    ui->qcustomplotWidget_3->graph(3)->setData(x1, y1);

    errorBars->setData(y1err);
    ui->qcustomplotWidget_3->graph(2)->rescaleAxes();
    ui->qcustomplotWidget_3->graph(3)->rescaleAxes(true);
    // setup look of bottom tick labels:
    ui->qcustomplotWidget_3->xAxis->setTickLabelRotation(30);
    ui->qcustomplotWidget_3->xAxis->ticker()->setTickCount(9);
    ui->qcustomplotWidget_3->xAxis->setNumberFormat("ebc");
    ui->qcustomplotWidget_3->xAxis->setNumberPrecision(1);
    ui->qcustomplotWidget_3->xAxis->moveRange(-10);
    // make top right axes clones of bottom left axes. Looks prettier:
    ui->qcustomplotWidget_3->axisRect()->setupFullAxesBox();
}

void MainWindow::demo_widget0()
{
    ui->qcustomplotWidget->legend->setVisible(true);
    ui->qcustomplotWidget->legend->setFont(QFont("Helvatica",9));
    ui->qcustomplotWidget->legend->setRowSpacing(-3);
    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;
    QPen pen;
    for(int i=0;i<shapes.size();++i)
    {
        ui->qcustomplotWidget->addGraph();
        pen.setColor(QColor(qSin(i*0.3)*100+100,qSin(i*0.6+0.7)*100+100,qSin(i*0.4+0.6)*100+100));
        QVector<double> x(10), y(10);
        for (int k=0; k<10; ++k)
        {
          x[k] = k/10.0 * 4*3.14 + 0.01;
          y[k] = 7*qSin(x[k])/x[k] + (shapes.size()-i)*5;
        }
        ui->qcustomplotWidget->graph()->setData(x,y);
        ui->qcustomplotWidget->graph()->rescaleAxes(true);//自动调整坐标轴的刻度大小
        ui->qcustomplotWidget->graph()->setPen(pen);
        ui->qcustomplotWidget->graph()->setName(QCPScatterStyle::staticMetaObject.enumerator(QCPScatterStyle::staticMetaObject.indexOfEnumerator("ScatterShape")).valueToKey(shapes.at(i)));
        ui->qcustomplotWidget->graph()->setLineStyle(QCPGraph::lsLine);
        if(shapes.at(i)!=QCPScatterStyle::ssCustom)
        {
            ui->qcustomplotWidget->graph()->setScatterStyle(QCPScatterStyle(shapes.at(i),10));
        }
        else
        {
            QPainterPath customScatterPath;
            for (int i=0; i<3; ++i)
              customScatterPath.cubicTo(qCos(2*M_PI*i/3.0)*9, qSin(2*M_PI*i/3.0)*9, qCos(2*M_PI*(i+0.9)/3.0)*9, qSin(2*M_PI*(i+0.9)/3.0)*9, 0, 0);
            ui->qcustomplotWidget->graph()->setScatterStyle(QCPScatterStyle(customScatterPath, QPen(Qt::black, 0), QColor(40, 70, 255, 50), 10));
        }
    }
    ui->qcustomplotWidget->rescaleAxes();
   // ui->qcustomplotWidget->xAxis->setTicks(false);
   // ui->qcustomplotWidget->yAxis->setTicks(false);
   // ui->qcustomplotWidget->xAxis->setTickLabels(false);
   // ui->qcustomplotWidget->yAxis->setTickLabels(false);
    ui->qcustomplotWidget->axisRect()->setupFullAxesBox();
}
void MainWindow::demo_widget4()
{
    ui->qcustomplotWidget_4->legend->setVisible(true);
    ui->qcustomplotWidget_4->legend->setFont(QFont("Helvetica",9));
    QPen pen;
    QStringList lineNames;
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    for (int i=QCPGraph::lsNone; i<=QCPGraph::lsImpulse; ++i)
    {
        ui->qcustomplotWidget_4->addGraph();
        pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
        ui->qcustomplotWidget_4->graph()->setPen(pen);
        ui->qcustomplotWidget_4->graph()->setName(lineNames.at(i-QCPGraph::lsNone));
        ui->qcustomplotWidget_4->graph()->setLineStyle((QCPGraph::LineStyle)i);
        ui->qcustomplotWidget_4->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        QVector<double> x(15), y(15);
        for (int j=0; j<15; ++j)
        {
          x[j] = j/15.0 * 5*3.14 + 0.01;
          y[j] = 7*qSin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
        }
        ui->qcustomplotWidget_4->graph()->setData(x, y);
        ui->qcustomplotWidget_4->graph()->rescaleAxes(true);
    }
    ui->qcustomplotWidget_4->yAxis->scaleRange(1.1, ui->qcustomplotWidget_4->yAxis->range().center());
    ui->qcustomplotWidget_4->xAxis->scaleRange(1.1, ui->qcustomplotWidget_4->xAxis->range().center());
    ui->qcustomplotWidget_4->axisRect()->setupFullAxesBox();
}

void MainWindow::demo_widget5()
{
    ui->qcustomplotWidget_5->axisRect()->setBackground(QPixmap("./solarpanels.jpg"));//使用图片做背景
    ui->qcustomplotWidget_5->addGraph();
    ui->qcustomplotWidget_5->graph()->setLineStyle(QCPGraph::lsLine);//线的风格
    QPen pen;
    pen.setColor(QColor(255, 200, 20, 200));
    pen.setStyle(Qt::DashLine);
    pen.setWidthF(2.5);
    ui->qcustomplotWidget_5->graph()->setPen(pen);
    ui->qcustomplotWidget_5->graph()->setBrush(QBrush(QColor(255,200,20,70)));
    ui->qcustomplotWidget_5->graph()->setScatterStyle(QCPScatterStyle(QPixmap("./sun.png")));//线的分割点的形状
    ui->qcustomplotWidget_5->graph()->setName("Data from Photovoltaic\nenergy barometer 2011");
    QVector<double> year, value;
    year  << 2005 << 2006 << 2007 << 2008  << 2009  << 2010 << 2011;
    value << 2.17 << 3.42 << 4.94 << 10.38 << 15.86 << 29.33 << 52.1;
    ui->qcustomplotWidget_5->graph()->setData(year, value);
    ui->qcustomplotWidget_5->plotLayout()->insertRow(0);
    ui->qcustomplotWidget_5->plotLayout()->addElement(0, 0, new QCPTextElement(ui->qcustomplotWidget_5, "Regenerative Energies", QFont("sans", 12, QFont::Bold)));
    ui->qcustomplotWidget_5->xAxis->setLabel("Year");
    ui->qcustomplotWidget_5->yAxis->setLabel("Installed Gigawatts of\nphotovoltaic in the European Union");
    ui->qcustomplotWidget_5->xAxis2->setVisible(true);
    ui->qcustomplotWidget_5->yAxis2->setVisible(true);
    ui->qcustomplotWidget_5->xAxis2->setTickLabels(false);
    ui->qcustomplotWidget_5->yAxis2->setTickLabels(false);
    ui->qcustomplotWidget_5->xAxis2->setTicks(false);
    ui->qcustomplotWidget_5->yAxis2->setTicks(false);
    ui->qcustomplotWidget_5->xAxis2->setSubTicks(false);
    ui->qcustomplotWidget_5->yAxis2->setSubTicks(false);
    ui->qcustomplotWidget_5->xAxis->setRange(2004.5, 2011.5);
    ui->qcustomplotWidget_5->yAxis->setRange(0, 52);
    // setup legend:
    ui->qcustomplotWidget_5->legend->setFont(QFont(font().family(), 7));
    ui->qcustomplotWidget_5->legend->setIconSize(50, 20);
    ui->qcustomplotWidget_5->legend->setVisible(true);
    ui->qcustomplotWidget_5->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
}

void MainWindow::demo_widget6()
{
    ui->qcustomplotWidget_6->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    double now = QDateTime::currentDateTime().toTime_t();//获取当前的时间
    srand(8);
    for (int gi=0; gi<5; ++gi)//创建6个图层
    {
      ui->qcustomplotWidget_6->addGraph();
      QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);//颜色
      ui->qcustomplotWidget_6->graph()->setLineStyle(QCPGraph::lsLine);//线型
      ui->qcustomplotWidget_6->graph()->setPen(QPen(color.lighter(10)));//
      ui->qcustomplotWidget_6->graph()->setBrush(QBrush(color));//曲线下面的阴影
      // generate random walk data:
      QVector<QCPGraphData> timeData(250);
      for (int i=0; i<250; ++i)
      {
        timeData[i].key = now + 24*3600*i;
        if (i == 0)
          timeData[i].value = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
        else
          timeData[i].value = qFabs(timeData[i-1].value)*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
      ui->qcustomplotWidget_6->graph()->data()->set(timeData);
    }
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    ui->qcustomplotWidget_6->xAxis->setTicker(dateTicker);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10, "a bit\nlow");
    textTicker->addTick(50, "quite\nhigh");
    ui->qcustomplotWidget_6->yAxis->setTicker(textTicker);
    ui->qcustomplotWidget_6->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    ui->qcustomplotWidget_6->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

    ui->qcustomplotWidget_6->xAxis->setLabel("Date");
    ui->qcustomplotWidget_6->yAxis->setLabel("Random wobbly lines value");
    // make top and right axes visible but without ticks and labels:
    ui->qcustomplotWidget_6->xAxis2->setVisible(true);
    ui->qcustomplotWidget_6->yAxis2->setVisible(true);
    ui->qcustomplotWidget_6->xAxis2->setTicks(false);
    ui->qcustomplotWidget_6->yAxis2->setTicks(false);
    ui->qcustomplotWidget_6->xAxis2->setTickLabels(false);
    ui->qcustomplotWidget_6->yAxis2->setTickLabels(false);
    // set axis ranges to show all data:
    ui->qcustomplotWidget_6->xAxis->setRange(now, now+24*3600*249);
    ui->qcustomplotWidget_6->yAxis->setRange(0, 60);
    // show legend with slightly transparent background brush:
    ui->qcustomplotWidget_6->legend->setVisible(true);
    ui->qcustomplotWidget_6->legend->setBrush(QColor(255, 255, 255, 150));
}
void MainWindow::demo_widget7()
{
    ui->qcustomplotWidget_7->addGraph();
    QPen redDotPen;
    redDotPen.setStyle(Qt::DotLine);
    redDotPen.setColor(QColor(170,100,100,180));
    redDotPen.setWidthF(2);
    ui->qcustomplotWidget_7->graph(0)->setPen(redDotPen);
    ui->qcustomplotWidget_7->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg")));//阴影用图片
    ui->qcustomplotWidget_7->addGraph();
    ui->qcustomplotWidget_7->graph(1)->setPen(QPen(Qt::red));

    // activate channel fill for graph 0 towards graph 1:
    ui->qcustomplotWidget_7->graph(0)->setChannelFillGraph(ui->qcustomplotWidget_7->graph(1));//两个曲线的封闭加阴影

    // generate data:
    QVector<double> x(250);
    QVector<double> y0(250), y1(250);
    for (int i=0; i<250; ++i)
    {
      // just playing with numbers, not much to learn here
      x[i] = 3*i/250.0;
      y0[i] = 1+qExp(-x[i]*x[i]*0.8)*(x[i]*x[i]+x[i]);
      y1[i] = 1-qExp(-x[i]*x[i]*0.4)*(x[i]*x[i])*0.1;
    }

    // pass data points to graphs:
    ui->qcustomplotWidget_7->graph(0)->setData(x, y0);
    ui->qcustomplotWidget_7->graph(1)->setData(x, y1);
    // activate top and right axes, which are invisible by default:
    ui->qcustomplotWidget_7->xAxis2->setVisible(true);
    ui->qcustomplotWidget_7->yAxis2->setVisible(true);
    // make tick labels invisible on top and right axis:
    ui->qcustomplotWidget_7->xAxis2->setTickLabels(false);
    ui->qcustomplotWidget_7->yAxis2->setTickLabels(false);
    // set ranges:
    ui->qcustomplotWidget_7->xAxis->setRange(0, 2.5);
    ui->qcustomplotWidget_7->yAxis->setRange(0.9, 1.6);
    // assign top/right axes same properties as bottom/left:
    ui->qcustomplotWidget_7->axisRect()->setupFullAxesBox();
}

void MainWindow::demo_widget8()
{
    ui->qcustomplotWidget_8->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->qcustomplotWidget_8->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->qcustomplotWidget_8->legend->setFont(legendFont);
    ui->qcustomplotWidget_8->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->qcustomplotWidget_8->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    // setup for graph 0: key axis left, value axis bottom
    // will contain left maxwell-like function
    ui->qcustomplotWidget_8->addGraph(ui->qcustomplotWidget_8->yAxis, ui->qcustomplotWidget_8->xAxis);
    ui->qcustomplotWidget_8->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    ui->qcustomplotWidget_8->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    ui->qcustomplotWidget_8->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->qcustomplotWidget_8->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
   // ui->qcustomplotWidget_8->graph(0)->setName("Left maxwell function");

    // setup for graph 1: key axis bottom, value axis left (those are the default axes)
    // will contain bottom maxwell-like function with error bars
    ui->qcustomplotWidget_8->addGraph();
    ui->qcustomplotWidget_8->graph(1)->setPen(QPen(Qt::red));
    ui->qcustomplotWidget_8->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
    ui->qcustomplotWidget_8->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
    ui->qcustomplotWidget_8->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
   // ui->qcustomplotWidget_8->graph(1)->setName("Bottom maxwell function");
    QCPErrorBars *errorBars = new QCPErrorBars(ui->qcustomplotWidget_8->xAxis, ui->qcustomplotWidget_8->yAxis);
    errorBars->removeFromLegend();
    errorBars->setDataPlottable(ui->qcustomplotWidget_8->graph(1));

    // setup for graph 2: key axis top, value axis right
    // will contain high frequency sine with low frequency beating:
    ui->qcustomplotWidget_8->addGraph(ui->qcustomplotWidget_8->xAxis2, ui->qcustomplotWidget_8->yAxis2);
    ui->qcustomplotWidget_8->graph(2)->setPen(QPen(Qt::blue));
    //ui->qcustomplotWidget_8->graph(2)->setName("High frequency sine");

    // setup for graph 3: same axes as graph 2
    // will contain low frequency beating envelope of graph 2
    ui->qcustomplotWidget_8->addGraph(ui->qcustomplotWidget_8->xAxis2, ui->qcustomplotWidget_8->yAxis2);
    QPen blueDotPen;
    blueDotPen.setColor(QColor(30, 40, 255, 150));
    blueDotPen.setStyle(Qt::DotLine);
    blueDotPen.setWidthF(4);
    ui->qcustomplotWidget_8->graph(3)->setPen(blueDotPen);
   // ui->qcustomplotWidget_8->graph(3)->setName("Sine envelope");

    // setup for graph 4: key axis right, value axis top
    // will contain parabolically distributed data points with some random perturbance
    ui->qcustomplotWidget_8->addGraph(ui->qcustomplotWidget_8->yAxis2, ui->qcustomplotWidget_8->xAxis2);
    ui->qcustomplotWidget_8->graph(4)->setPen(QColor(50, 50, 50, 255));
    ui->qcustomplotWidget_8->graph(4)->setLineStyle(QCPGraph::lsNone);
    ui->qcustomplotWidget_8->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
   // ui->qcustomplotWidget_8->graph(4)->setName("Some random data around\na quadratic function");

    // generate data, just playing with numbers, not much to learn here:
    QVector<double> x0(25), y0(25);
    QVector<double> x1(15), y1(15), y1err(15);
    QVector<double> x2(250), y2(250);
    QVector<double> x3(250), y3(250);
    QVector<double> x4(250), y4(250);
    for (int i=0; i<25; ++i) // data for graph 0
    {
      x0[i] = 3*i/25.0;
      y0[i] = qExp(-x0[i]*x0[i]*0.8)*(x0[i]*x0[i]+x0[i]);
    }
    for (int i=0; i<15; ++i) // data for graph 1
    {
      x1[i] = 3*i/15.0;;
      y1[i] = qExp(-x1[i]*x1[i])*(x1[i]*x1[i])*2.6;
      y1err[i] = y1[i]*0.25;
    }
    for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
    {
      x2[i] = i/250.0*3*M_PI;
      x3[i] = x2[i];
      x4[i] = i/250.0*100-50;
      y2[i] = qSin(x2[i]*12)*qCos(x2[i])*10;
      y3[i] = qCos(x3[i])*10;
      y4[i] = 0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI;
    }

    // pass data points to graphs:
    ui->qcustomplotWidget_8->graph(0)->setData(x0, y0);
    ui->qcustomplotWidget_8->graph(1)->setData(x1, y1);
    errorBars->setData(y1err);
    ui->qcustomplotWidget_8->graph(2)->setData(x2, y2);
    ui->qcustomplotWidget_8->graph(3)->setData(x3, y3);
    ui->qcustomplotWidget_8->graph(4)->setData(x4, y4);
    // activate top and right axes, which are invisible by default:
    ui->qcustomplotWidget_8->xAxis2->setVisible(true);
    ui->qcustomplotWidget_8->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    ui->qcustomplotWidget_8->xAxis->setRange(0, 2.7);
    ui->qcustomplotWidget_8->yAxis->setRange(0, 2.6);
    ui->qcustomplotWidget_8->xAxis2->setRange(0, 3.0*M_PI);
    ui->qcustomplotWidget_8->yAxis2->setRange(-70, 35);
    // set pi ticks on top axis:
    ui->qcustomplotWidget_8->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
    // add title layout element:
    ui->qcustomplotWidget_8->plotLayout()->insertRow(0);
    ui->qcustomplotWidget_8->plotLayout()->addElement(0, 0, new QCPTextElement(ui->qcustomplotWidget_8, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
    // set labels:
    ui->qcustomplotWidget_8->xAxis->setLabel("Bottom axis with outward ticks");
    ui->qcustomplotWidget_8->yAxis->setLabel("Left axis label");
    ui->qcustomplotWidget_8->xAxis2->setLabel("Top axis label");
    ui->qcustomplotWidget_8->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:
    ui->qcustomplotWidget_8->xAxis->setTickLength(0, 5);
    ui->qcustomplotWidget_8->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:
    ui->qcustomplotWidget_8->yAxis2->setTickLength(3, 3);
    ui->qcustomplotWidget_8->yAxis2->setSubTickLength(1, 1);
}

void MainWindow::mouseWheel()
{
    if(ui->qcustomplotWidget->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
    {
        ui->qcustomplotWidget->axisRect()->setRangeZoom(ui->qcustomplotWidget->xAxis->orientation());
    }
    else if (ui->qcustomplotWidget->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      {
        ui->qcustomplotWidget->axisRect()->setRangeZoom(ui->qcustomplotWidget->yAxis->orientation());
      }
      else
      {
        ui->qcustomplotWidget->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
      }
}
void MainWindow::selectionChanged()
{
  /*
   normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
   the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
   and the axis base line together. However, the axis label shall be selectable individually.

   The selection state of the left and right axes shall be synchronized as well as the state of the
   bottom and top axes.

   Further, we want to synchronize the selection of the graphs with the selection state of the respective
   legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
   or on its legend item.
  */

  // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->qcustomplotWidget->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->qcustomplotWidget->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->qcustomplotWidget->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->qcustomplotWidget->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->qcustomplotWidget->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->qcustomplotWidget->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }
  // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->qcustomplotWidget->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->qcustomplotWidget->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->qcustomplotWidget->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->qcustomplotWidget->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->qcustomplotWidget->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->qcustomplotWidget->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }

  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<ui->qcustomplotWidget->graphCount(); ++i)
  {
    QCPGraph *graph = ui->qcustomplotWidget->graph(i);
    QCPPlottableLegendItem *item = ui->qcustomplotWidget->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);
   //   graph->setSelected(true);
    }
  }
}
