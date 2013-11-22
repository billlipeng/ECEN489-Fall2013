#-------------------------------------------------
#
# Project created by QtCreator 2013-11-20T16:20:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

TARGET = Hands_ON
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    Serial.cpp \
    Reading.cpp \
    Reader.cpp \
    qcustomplot.cpp \
    performance_metric.cpp

HEADERS  += mainwindow.h \
    SerialClass.h \
    Reading.h \
    Reader.h \
    qcustomplot.h \
    performance_metric.h

FORMS    += mainwindow.ui
