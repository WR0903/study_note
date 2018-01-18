/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1001, 632);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qcustomplotWidget = new QCustomPlot(centralWidget);
        qcustomplotWidget->setObjectName(QStringLiteral("qcustomplotWidget"));
        qcustomplotWidget->setGeometry(QRect(10, 0, 421, 281));
        qcustomplotWidget_1 = new QCustomPlot(centralWidget);
        qcustomplotWidget_1->setObjectName(QStringLiteral("qcustomplotWidget_1"));
        qcustomplotWidget_1->setGeometry(QRect(430, 0, 371, 281));
        qcustomplotWidget_2 = new QCustomPlot(centralWidget);
        qcustomplotWidget_2->setObjectName(QStringLiteral("qcustomplotWidget_2"));
        qcustomplotWidget_2->setGeometry(QRect(800, 0, 351, 281));
        qcustomplotWidget_3 = new QCustomPlot(centralWidget);
        qcustomplotWidget_3->setObjectName(QStringLiteral("qcustomplotWidget_3"));
        qcustomplotWidget_3->setGeometry(QRect(10, 280, 421, 241));
        qcustomplotWidget_4 = new QCustomPlot(centralWidget);
        qcustomplotWidget_4->setObjectName(QStringLiteral("qcustomplotWidget_4"));
        qcustomplotWidget_4->setGeometry(QRect(430, 280, 371, 241));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1001, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
