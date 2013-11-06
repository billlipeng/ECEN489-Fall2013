#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T22:53:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

TARGET = reader_serial_test
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    Serial.cpp \
    Reading.cpp \
    Reader.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    SerialClass.h \
    Reading.h \
    Reader.h \
    qcustomplot.h

FORMS    += mainwindow.ui
