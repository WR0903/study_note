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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *printAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *selectAllAction;
    QAction *dateTimeAction;
    QAction *fontAction;
    QAction *colorAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_G;
    QMenu *menu_V;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QStringLiteral("newAction"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon1);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon2);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QStringLiteral("saveAsAction"));
        printAction = new QAction(MainWindow);
        printAction->setObjectName(QStringLiteral("printAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QStringLiteral("redoAction"));
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAction->setIcon(icon3);
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QStringLiteral("cutAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutAction->setIcon(icon4);
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAction->setIcon(icon5);
        selectAllAction = new QAction(MainWindow);
        selectAllAction->setObjectName(QStringLiteral("selectAllAction"));
        dateTimeAction = new QAction(MainWindow);
        dateTimeAction->setObjectName(QStringLiteral("dateTimeAction"));
        fontAction = new QAction(MainWindow);
        fontAction->setObjectName(QStringLiteral("fontAction"));
        colorAction = new QAction(MainWindow);
        colorAction->setObjectName(QStringLiteral("colorAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/image/ubuntu.png);"));

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 31));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_G = new QMenu(menuBar);
        menu_G->setObjectName(QStringLiteral("menu_G"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_G->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu->addAction(newAction);
        menu->addAction(openAction);
        menu->addAction(saveAction);
        menu->addAction(saveAsAction);
        menu->addSeparator();
        menu->addAction(printAction);
        menu->addAction(exitAction);
        menu_E->addAction(undoAction);
        menu_E->addAction(redoAction);
        menu_E->addSeparator();
        menu_E->addAction(copyAction);
        menu_E->addAction(cutAction);
        menu_E->addAction(pasteAction);
        menu_E->addAction(selectAllAction);
        menu_E->addSeparator();
        menu_E->addAction(dateTimeAction);
        menu_E->addAction(fontAction);
        menu_E->addAction(colorAction);
        mainToolBar->addAction(newAction);
        mainToolBar->addAction(openAction);
        mainToolBar->addAction(saveAction);
        mainToolBar->addAction(copyAction);
        mainToolBar->addAction(cutAction);
        mainToolBar->addAction(pasteAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newAction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", 0));
        openAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", 0));
        saveAction->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", 0));
        saveAsAction->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", 0));
        printAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260(&P)", 0));
        exitAction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        undoAction->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", 0));
        redoAction->setText(QApplication::translate("MainWindow", "\351\207\215\345\201\232(&R)", 0));
        copyAction->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", 0));
        cutAction->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&X)", 0));
        pasteAction->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&V)", 0));
        selectAllAction->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", 0));
        dateTimeAction->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237(&D)", 0));
        fontAction->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223(&F)", 0));
        colorAction->setText(QApplication::translate("MainWindow", "\351\242\234\350\211\262(&L)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", 0));
        menu_G->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", 0));
        menu_V->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", 0));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
