/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *label;
    QLabel *movieLable;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *helloButton;
    QPushButton *noButton;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(427, 373);
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 171, 61));
        movieLable = new QLabel(about);
        movieLable->setObjectName(QStringLiteral("movieLable"));
        movieLable->setGeometry(QRect(80, 80, 231, 161));
        widget = new QWidget(about);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 290, 178, 35));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        helloButton = new QPushButton(widget);
        helloButton->setObjectName(QStringLiteral("helloButton"));

        horizontalLayout->addWidget(helloButton);

        noButton = new QPushButton(widget);
        noButton->setObjectName(QStringLiteral("noButton"));

        horizontalLayout->addWidget(noButton);

        label->raise();
        movieLable->raise();
        noButton->raise();
        helloButton->raise();
        noButton->raise();
        noButton->raise();

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", 0));
        label->setText(QApplication::translate("about", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600; font-style:italic; text-decoration: underline; color:#ff2d56;\">\346\226\260\345\271\264\345\277\253\344\271\220</span></p></body></html>", 0));
        movieLable->setText(QString());
        helloButton->setText(QApplication::translate("about", "\344\275\240\345\245\275", 0));
        noButton->setText(QApplication::translate("about", "\344\275\240\344\270\215\345\245\275", 0));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
