#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T23:42:58
#
#-------------------------------------------------

QT       += core gui
QT	     += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Muster_Maker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    commwidget.cpp \
    dbmanager.cpp \
    newmusterdialog.cpp \
    ubiquity.cpp \
    unit.cpp \
    unitframe.cpp

HEADERS  += mainwindow.h \
    battlesize.h \
    commwidget.h \
    constants.h \
    dbmanager.h \
    newmusterdialog.h \
    ubiquity.h \
    unit.h \
    unitframe.h

FORMS    += mainwindow.ui \
    commwidget.ui \
    newmusterdialog.ui \
    unitframe.ui

CONFIG += static
