QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \ \
    consumer.cpp \
    test.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    consumer.h \
    test.h
