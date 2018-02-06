#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(393,187);
    this->setMinimumSize(393,187);
}

Widget::~Widget()
{
    delete ui;
}
