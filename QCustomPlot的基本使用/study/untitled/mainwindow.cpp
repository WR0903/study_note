#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    demo1();
  //  demo2();
  //  demo3();
  //  demo4();
    demo5();
    connect(ui->qcustomplotWidget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));//连接鼠标点击信号和槽
    connect(ui->qcustomplotWidget, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));//连接鼠标滚轮信号和槽
      //  connect(ui->qcustomplotWidget, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));//连接曲线选择信号和槽

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::demo1()
{
    ui->qcustomplotWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(0,255,255));// 背景颜色
    ui->qcustomplotWidget->setBackground(qBrush);
    ui->qcustomplotWidget->legend->setVisible(true);

    ui->qcustomplotWidget->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget->xAxis->setRange(0.0,255.0);//数值范围

    ui->qcustomplotWidget->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget->yAxis->setSubTicks(true);
    ui->qcustomplotWidget->yAxis->setRange(-1,1.0);//数值范围

}

void MainWindow::demo2()//普通的曲线
{
    QVector<double>x(251),y(251);
    for(int i=0;i<251;++i)
    {
        x[i]=i;
        y[i]=qCos(i/10.0);
    }
    ui->qcustomplotWidget->addGraph();//添加一个图层
    ui->qcustomplotWidget->graph(0)->setPen(QPen(Qt::red));//将线条颜色设置为蓝色
    ui->qcustomplotWidget->graph(0)->setData(x,y);//在这个图层添加数据
    ui->qcustomplotWidget->xAxis->setLabel("x");//设置x轴
    ui->qcustomplotWidget->yAxis->setLabel("y");//设置y轴
    ui->qcustomplotWidget->xAxis->setRange(0,255);//设置x轴的范围
    ui->qcustomplotWidget->yAxis->setRange(-1,1);//设置y轴的范围
}
void MainWindow::demo3()//普通曲线下方的阴影
{
    ui->qcustomplotWidget->addGraph();//添加一个图层
    ui->qcustomplotWidget->graph(1)->setPen(QPen(Qt::blue));//将线条颜色设置为蓝色
    ui->qcustomplotWidget->graph(1)->setBrush(QBrush(QColor(0,0,255,200)));//曲线下面的阴影//前3个参数是颜色，第四个参数是透明度
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
      x[i] = i;
      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
      y1[i] = qExp(-i/150.0);              // exponential envelope
    }
    ui->qcustomplotWidget->graph(1)->setData(x, y0);
    ui->qcustomplotWidget->xAxis2->setVisible(true);
    ui->qcustomplotWidget->xAxis2->setTickLabels(false);
    ui->qcustomplotWidget->yAxis2->setVisible(true);
    ui->qcustomplotWidget->yAxis2->setTickLabels(false);

}
void MainWindow::demo4()
{
    ui->qcustomplotWidget->legend->setVisible(true);//可见
    ui->qcustomplotWidget->legend->setFont(QFont("Helvetica",9));//字体
    ui->qcustomplotWidget->setLocale(QLocale(QLocale::English,QLocale::UnitedKingdom));
    ui->qcustomplotWidget->addGraph();//添加一个图层
    QPen pen;
    pen.setStyle(Qt::DotLine);//点线
    pen.setWidth(1);//线宽
    pen.setColor(QColor(180,180,180));//颜色
    ui->qcustomplotWidget->graph(2)->setName("Confidence Band 68%");//图层名称
    ui->qcustomplotWidget->graph(2)->setPen(pen);
    ui->qcustomplotWidget->graph(2)->setBrush(QBrush(QColor(255,50,30,20)));//线下面的阴影
    ui->qcustomplotWidget->addGraph();//添加一个图层
    ui->qcustomplotWidget->legend->removeItem(ui->qcustomplotWidget->legend->itemCount()-1); // 不要在图例中显示两个置信带图
    ui->qcustomplotWidget->graph(3)->setPen(pen);
    ui->qcustomplotWidget->graph(2)->setChannelFillGraph(ui->qcustomplotWidget->graph(3));
    ui->qcustomplotWidget->addGraph();
    pen.setStyle(Qt::DashLine);//虚线
    pen.setWidth(2);//线宽
    pen.setColor(Qt::red);//红色
    ui->qcustomplotWidget->graph(4)->setPen(pen);
    ui->qcustomplotWidget->graph(4)->setName("Theory Curve");
    ui->qcustomplotWidget->addGraph();
    ui->qcustomplotWidget->graph(5)->setPen(QPen(Qt::blue));
    ui->qcustomplotWidget->graph(5)->setLineStyle(QCPGraph::lsNone);
    ui->qcustomplotWidget->graph(5)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCross, 4));
    QCPErrorBars *errorBars = new QCPErrorBars(ui->qcustomplotWidget->xAxis, ui->qcustomplotWidget->yAxis);
    errorBars->removeFromLegend();
    errorBars->setAntialiased(false);
    errorBars->setDataPlottable(ui->qcustomplotWidget->graph(3));
    errorBars->setPen(QPen(QColor(180,180,180)));
    ui->qcustomplotWidget->graph(5)->setName("Measurement");
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
    ui->qcustomplotWidget->graph(2)->setData(x0, yConfUpper);
    ui->qcustomplotWidget->graph(3)->setData(x0, yConfLower);
    ui->qcustomplotWidget->graph(4)->setData(x0, y0);
    ui->qcustomplotWidget->graph(5)->setData(x1, y1);

    errorBars->setData(y1err);
    ui->qcustomplotWidget->graph(4)->rescaleAxes();
    ui->qcustomplotWidget->graph(5)->rescaleAxes(true);
    // setup look of bottom tick labels:
    ui->qcustomplotWidget->xAxis->setTickLabelRotation(30);
    ui->qcustomplotWidget->xAxis->ticker()->setTickCount(9);
    ui->qcustomplotWidget->xAxis->setNumberFormat("ebc");
    ui->qcustomplotWidget->xAxis->setNumberPrecision(1);
    ui->qcustomplotWidget->xAxis->moveRange(-10);
    // make top right axes clones of bottom left axes. Looks prettier:
    ui->qcustomplotWidget->axisRect()->setupFullAxesBox();
}

void MainWindow::demo5()
{
    ui->qcustomplotWidget->legend->setVisible(true);
    ui->qcustomplotWidget->legend->setFont(QFont("Helvatica",9));
    ui->qcustomplotWidget->legend->setRowSpacing(-3);
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
