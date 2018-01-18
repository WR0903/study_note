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
