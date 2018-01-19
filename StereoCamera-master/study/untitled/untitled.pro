TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CameraCalibration.cpp \
    StereoMatch.cpp

HEADERS += \
    CameraCalibration.h \
    StereoMatch.h
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_*.so
