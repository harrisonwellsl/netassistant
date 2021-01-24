#-------------------------------------------------
#
# Project created by QtCreator 2021-01-23T12:20:20
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = net_assistant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpserver.cpp \
    tcpclient.cpp

HEADERS  += mainwindow.h \
    tcpserver.h \
    tcpclient.h

FORMS    += mainwindow.ui
