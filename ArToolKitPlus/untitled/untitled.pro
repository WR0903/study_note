TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

unix|win32: LIBS += -lARToolKitPlus
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_*.so