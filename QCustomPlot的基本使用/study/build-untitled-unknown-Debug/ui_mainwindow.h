/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *qcustomplotWidget;
    QCustomPlot *qcustomplotWidget_1;
    QCustomPlot *qcustomplotWidget_2;
    QCustomPlot *qcustomplotWidget_3;
    QCustomPlot *qcustomplotWidget_4;
    QCustomPlot *qcustomplotWidget_5;
    QCustomPlot *qcustomplotWidget_6;
    QCustomPlot *qcustomplotWidget_7;
    QCustomPlot *qcustomplotWidget_8;
    QMenuBar *menuBar;
    QMenu *menu1;
    QMenu *menu2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1188, 849);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qcustomplotWidget = new QCustomPlot(centralWidget);
        qcustomplotWidget->setObjectName(QString::fromUtf8("qcustomplotWidget"));
        qcustomplotWidget->setGeometry(QRect(10, 0, 421, 261));
        qcustomplotWidget_1 = new QCustomPlot(centralWidget);
        qcustomplotWidget_1->setObjectName(QString::fromUtf8("qcustomplotWidget_1"));
        qcustomplotWidget_1->setGeometry(QRect(430, 0, 371, 261));
        qcustomplotWidget_2 = new QCustomPlot(centralWidget);
        qcustomplotWidget_2->setObjectName(QString::fromUtf8("qcustomplotWidget_2"));
        qcustomplotWidget_2->setGeometry(QRect(800, 0, 351, 261));
        qcustomplotWidget_3 = new QCustomPlot(centralWidget);
        qcustomplotWidget_3->setObjectName(QString::fromUtf8("qcustomplotWidget_3"));
        qcustomplotWidget_3->setGeometry(QRect(10, 260, 421, 241));
        qcustomplotWidget_4 = new QCustomPlot(centralWidget);
        qcustomplotWidget_4->setObjectName(QString::fromUtf8("qcustomplotWidget_4"));
        qcustomplotWidget_4->setGeometry(QRect(430, 260, 371, 241));
        qcustomplotWidget_5 = new QCustomPlot(centralWidget);
        qcustomplotWidget_5->setObjectName(QString::fromUtf8("qcustomplotWidget_5"));
        qcustomplotWidget_5->setGeometry(QRect(800, 260, 351, 241));
        qcustomplotWidget_6 = new QCustomPlot(centralWidget);
        qcustomplotWidget_6->setObjectName(QString::fromUtf8("qcustomplotWidget_6"));
        qcustomplotWidget_6->setGeometry(QRect(10, 500, 421, 211));
        qcustomplotWidget_7 = new QCustomPlot(centralWidget);
        qcustomplotWidget_7->setObjectName(QString::fromUtf8("qcustomplotWidget_7"));
        qcustomplotWidget_7->setGeometry(QRect(430, 500, 371, 211));
        qcustomplotWidget_8 = new QCustomPlot(centralWidget);
        qcustomplotWidget_8->setObjectName(QString::fromUtf8("qcustomplotWidget_8"));
        qcustomplotWidget_8->setGeometry(QRect(800, 500, 351, 211));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 31));
        menu1 = new QMenu(menuBar);
        menu1->setObjectName(QString::fromUtf8("menu1"));
        menu2 = new QMenu(menuBar);
        menu2->setObjectName(QString::fromUtf8("menu2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu1->menuAction());
        menuBar->addAction(menu2->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        menu1->setTitle(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        menu2->setTitle(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
