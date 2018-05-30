#-------------------------------------------------
#
# Project created by QtCreator 2018-05-29T14:13:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = untitled1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    marderid.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    marderid.h \
    qcustomplot.h

FORMS    += mainwindow.ui

unix|win32: LIBS += -lARToolKitPlus
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_*.so
