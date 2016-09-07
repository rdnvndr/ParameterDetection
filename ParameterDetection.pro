QT += core
QT -= gui

TARGET = ParameterDetection
CONFIG += console

TEMPLATE = app

SOURCES += main.cpp \
    thread.cpp \
    element.cpp

HEADERS += \
    thread.h \
    element.h
