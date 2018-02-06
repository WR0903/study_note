/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *cmdLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *cancleButton;
    QPushButton *browserButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(362, 152);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 20, 271, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        infoLabel = new QLabel(widget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        verticalLayout->addWidget(infoLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        cmdLineEdit = new QLineEdit(widget);
        cmdLineEdit->setObjectName(QStringLiteral("cmdLineEdit"));

        horizontalLayout_2->addWidget(cmdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        submitButton = new QPushButton(widget);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout->addWidget(submitButton);

        cancleButton = new QPushButton(widget);
        cancleButton->setObjectName(QStringLiteral("cancleButton"));

        horizontalLayout->addWidget(cancleButton);

        browserButton = new QPushButton(widget);
        browserButton->setObjectName(QStringLiteral("browserButton"));

        horizontalLayout->addWidget(browserButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        infoLabel->setText(QApplication::translate("Widget", "\350\257\267\345\234\250\344\270\213\351\235\242\347\232\204\345\221\275\344\273\244\350\241\214\344\270\255\350\276\223\345\205\245\345\221\275\344\273\244", 0));
        label->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\357\274\232", 0));
        submitButton->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", 0));
        cancleButton->setText(QApplication::translate("Widget", "\345\217\226\346\266\210", 0));
        browserButton->setText(QApplication::translate("Widget", "\346\265\217\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
