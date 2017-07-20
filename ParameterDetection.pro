QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ParameterDetection
CONFIG += console

TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    thread.cpp \
    element.cpp

HEADERS += \
    mainwindow.h \
    thread.h \
    element.h

FORMS    += mainwindow.ui
RESOURCES += qrc.qrc
