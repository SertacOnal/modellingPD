#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T15:27:50
#
#-------------------------------------------------

QT       += core gui \
            opengl \
            widgets \
            multimedia \
            multimediawidgets

TARGET = handmodeler
TEMPLATE = app


SOURCES += main.cpp \
    obj_load.cpp \
    base.cpp \
    mainwindow.cpp \
    data_load.cpp

HEADERS  += \
    obj_load.h \
    base.h \
    mainwindow.h \
    data_load.h \
    lcdnumber.h

DISTFILES +=

RESOURCES += \
    models.qrc

FORMS += \
    mainwindow.ui


