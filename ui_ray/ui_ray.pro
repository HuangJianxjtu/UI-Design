#-------------------------------------------------
#
# Project created by QtCreator 2018-11-02T10:49:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui_ray
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp
        INCLUDEPATH += .
        INCLUDEPATH += /usr/local/include
        INCLUDEPATH += /usr/local/include/opencv
        INCLUDEPATH += /usr/local/include/opencv2
        INCLUDEPATH += /usr/local/include/opencv2/core
        INCLUDEPATH += /usr/local/include/opencv2/highgui
        INCLUDEPATH += /usr/local/include/opencv2/imgproc
        INCLUDEPATH += /usr/local/include/opencv2/flann
        INCLUDEPATH += /usr/local/include/opencv2/photo
        INCLUDEPATH += /usr/local/include/opencv2/video
        INCLUDEPATH += /usr/local/include/opencv2/features2d
        INCLUDEPATH += /usr/local/include/opencv2/objdetect
        INCLUDEPATH += /usr/local/include/opencv2/calib3d
        INCLUDEPATH += /usr/local/include/opencv2/ml
        INCLUDEPATH += /usr/local/include/opencv2/contrib
        LIBS += `pkg-config opencv --cflags --libs`

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
