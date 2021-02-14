QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \ \
    mypool.cpp \
    mypoolitem.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    interfaces/ipool.h \
    interfaces/ipoolitem.h \
    mypool.h \
    mypoolitem.h
