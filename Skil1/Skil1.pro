QT += core
QT -= gui

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    interface.cpp \
    manager.cpp

HEADERS += \
    person.h \
    interface.h \
    manager.h

