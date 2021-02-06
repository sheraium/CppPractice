QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

SOURCES += main.cpp
CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = hello
