#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T14:16:14
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11

TARGET = FlipperDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flipperinterface.cpp \
    qcustomplot.cpp \
    graph.cpp \
    mysqlinterface.cpp \
    notification.cpp \
    onlinedatabaseinterface.cpp


HEADERS  += mainwindow.h \
    flipperinterface.h \
    qcustomplot.h \


FORMS    += mainwindow.ui

