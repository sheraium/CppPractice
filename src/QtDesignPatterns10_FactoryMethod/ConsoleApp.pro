QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \
    longdelay.cpp \
    shortdelay.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    interfaces/idelay.h \
    longdelay.h \
    shortdelay.h
