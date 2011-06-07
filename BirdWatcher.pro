#-------------------------------------------------
#
# Project created by QtCreator 2011-06-06T19:53:44
#
#-------------------------------------------------


QWT_ROOT = /home/wasabi/Programming/qwt-6.0/..
QT       += core gui

TARGET = BirdWatcher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    curvedata.cpp \
    plot.cpp \
    samplingthread.cpp \
    knob.cpp \
    signaldata.cpp \
    wheelbox.cpp \
    attitude_indicator.cpp \
    speedo_meter.cpp \
    panel.cpp \
    simulationthread.cpp

HEADERS  += mainwindow.h \
    curvedata.h \
    plot.h \
    samplingthread.h \
    knob.h \
    signaldata.h \
    wheelbox.h \
    attitude_indicator.h \
    speedo_meter.h \
    panel.h \
    settings.h \
    simulationthread.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/qwt-6.0.1-svn/include
LIBS += -L/usr/local/qwt-6.0.1-svn/lib -lqwt
