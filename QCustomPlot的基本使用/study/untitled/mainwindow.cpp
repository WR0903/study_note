#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->qcustomplotWidget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectAxes |QCP::iSelectLegend | QCP::iSelectPlottables);
    QBrush qBrush(QColor(0,255,255));// 背景颜色
    ui->qcustomplotWidget->setBackground(qBrush);
    ui->qcustomplotWidget->legend->setVisible(true);

    ui->qcustomplotWidget->xAxis->setLabel("Time Axis(t/s)");
    ui->qcustomplotWidget->xAxis->setTicks(true);//设置刻度使能
    ui->qcustomplotWidget->xAxis->setRange(0.0,200.0);//数值范围

    ui->qcustomplotWidget->yAxis->setLabel("EEG Channel");//设置ｙ轴
    ui->qcustomplotWidget->yAxis->setTicks(true);
    //ui->qcustomplotWidget->yAxis->setAutoTickStep(true);
    ui->qcustomplotWidget->yAxis->setSubTicks(true);
    ui->qcustomplotWidget->yAxis->setRange(8000.0,10000.0);//数值范围


   QCPGraph *graph1 = ui->qcustomplotWidget->addGraph();//增加一条曲线图层
   QCPGraph *graph2 = ui->qcustomplotWidget->addGraph();//增加一条曲线图层

   QVector<double> x(101), y(101); // initialize with entries 0..100
   for (int i=0; i<101; ++i)
   {
     x[i] = i/50.0 - 1; // x goes from -1 to 1
     y[i] = x[i]*x[i]; // let's plot a quadratic function
   }
    //QCPScatterStyle QCPcs1(QCPScatterStyle::ssSquare, QColor(255,0,0),QColor(255,0,0),3);//设置折线图的点的形状及颜色
        QPen qPen1(QColor(255,0,0));
    //   graph_1->setScatterStyle(QCPcs1);
        graph1->setPen(qPen1);//设置画笔颜色
        graph1->setData(x,y);
        graph1->setName(QString("F3"));


    //QCPScatterStyle QCPcs2(QCPScatterStyle::ssCircle, QColor(0,255,0),QColor(0,255,0),3);//设置折线图的点的形状及颜色
        QPen qPen2(QColor(0,255,0));
    //   graph2->setScatterStyle(QCPcs2);
        graph2->setPen(qPen2);//设置画笔颜色
        //graph2->setData(x,y);
        graph2->setName(QString("F4"));

        connect(ui->qcustomplotWidget, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));//连接鼠标点击信号和槽
        connect(ui->qcustomplotWidget, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));//连接鼠标滚轮信号和槽
      //  connect(ui->qcustomplotWidget, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));//连接曲线选择信号和槽

}

MainWindow::~MainWindow()
{
    delete ui;
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
