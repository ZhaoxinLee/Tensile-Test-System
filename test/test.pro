#-------------------------------------------------
#
# Project created by QtCreator 2022-02-22T11:07:51
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
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

CONFIG += c++11

SOURCES += \
        callbacks.cpp \
        daq.cpp \
        main.cpp \
        mainwindow.cpp \
        serialworker.cpp

HEADERS += \
        NIDAQmx.h \
        callbacks.h \
        daq.h \
        mainwindow.h \
        serialworker.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# NI DAQ Libraries
# For 32bit compiling
#LIBS += "C:/Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/lib/msvc/NIDAQmx.lib"
#INCLUDEPATH += "C:/Program Files (x86)/National Instruments/NI-DAQ/DAQmx ANSI C Dev/include"
# For 64 bit compiling
INCLUDEPATH +=  "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\include"
LIBS += "C:\Program Files (x86)\National Instruments\Shared\ExternalCompilerSupport\C\lib64\msvc/NIDAQmx.lib"
