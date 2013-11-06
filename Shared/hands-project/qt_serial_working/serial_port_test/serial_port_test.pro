#-------------------------------------------------
#
# Project created by QtCreator 2013-10-29T20:48:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

TARGET = serial_port_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    Reading.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    Reading.h

FORMS    += mainwindow.ui
