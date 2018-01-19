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
#include <QtWidgets/QMenu>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1188, 849);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        qcustomplotWidget = new QCustomPlot(centralWidget);
        qcustomplotWidget->setObjectName(QStringLiteral("qcustomplotWidget"));
        qcustomplotWidget->setGeometry(QRect(10, 0, 421, 261));
        qcustomplotWidget_1 = new QCustomPlot(centralWidget);
        qcustomplotWidget_1->setObjectName(QStringLiteral("qcustomplotWidget_1"));
        qcustomplotWidget_1->setGeometry(QRect(430, 0, 371, 261));
        qcustomplotWidget_2 = new QCustomPlot(centralWidget);
        qcustomplotWidget_2->setObjectName(QStringLiteral("qcustomplotWidget_2"));
        qcustomplotWidget_2->setGeometry(QRect(800, 0, 351, 261));
        qcustomplotWidget_3 = new QCustomPlot(centralWidget);
        qcustomplotWidget_3->setObjectName(QStringLiteral("qcustomplotWidget_3"));
        qcustomplotWidget_3->setGeometry(QRect(10, 260, 421, 241));
        qcustomplotWidget_4 = new QCustomPlot(centralWidget);
        qcustomplotWidget_4->setObjectName(QStringLiteral("qcustomplotWidget_4"));
        qcustomplotWidget_4->setGeometry(QRect(430, 260, 371, 241));
        qcustomplotWidget_5 = new QCustomPlot(centralWidget);
        qcustomplotWidget_5->setObjectName(QStringLiteral("qcustomplotWidget_5"));
        qcustomplotWidget_5->setGeometry(QRect(800, 260, 351, 241));
        qcustomplotWidget_6 = new QCustomPlot(centralWidget);
        qcustomplotWidget_6->setObjectName(QStringLiteral("qcustomplotWidget_6"));
        qcustomplotWidget_6->setGeometry(QRect(10, 500, 421, 211));
        qcustomplotWidget_7 = new QCustomPlot(centralWidget);
        qcustomplotWidget_7->setObjectName(QStringLiteral("qcustomplotWidget_7"));
        qcustomplotWidget_7->setGeometry(QRect(430, 500, 371, 211));
        qcustomplotWidget_8 = new QCustomPlot(centralWidget);
        qcustomplotWidget_8->setObjectName(QStringLiteral("qcustomplotWidget_8"));
        qcustomplotWidget_8->setGeometry(QRect(800, 500, 351, 211));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1188, 31));
        menu1 = new QMenu(menuBar);
        menu1->setObjectName(QStringLiteral("menu1"));
        menu2 = new QMenu(menuBar);
        menu2->setObjectName(QStringLiteral("menu2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu1->menuAction());
        menuBar->addAction(menu2->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        menu1->setTitle(QApplication::translate("MainWindow", "1", 0));
        menu2->setTitle(QApplication::translate("MainWindow", "2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
