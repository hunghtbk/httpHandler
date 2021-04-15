#-------------------------------------------------
#
# Project created by QtCreator 2013-10-02T21:09:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HttpWindow
TEMPLATE = app


SOURCES += main.cpp \
    Downloader.cpp

HEADERS  += \
    Downloader.h

FORMS    += httpwindow.ui
