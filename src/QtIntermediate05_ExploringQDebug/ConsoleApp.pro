QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \ \
    logger.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    logger.h
