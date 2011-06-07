#-------------------------------------------------
#
# Project created by QtCreator 2011-06-07T11:12:53
#
#-------------------------------------------------

QT       += core gui

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    knob.cpp

HEADERS  += mainwindow.h \
    knob.h

FORMS    += mainwindow.ui


INCLUDEPATH += /usr/local/qwt-6.0.1-svn/include
LIBS += -L/usr/local/qwt-6.0.1-svn/lib -lqwt
