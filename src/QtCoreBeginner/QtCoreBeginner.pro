QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

HEADERS += \
    destination.h \
    radio.h \
    source.h \
    station.h

SOURCES += main.cpp \
    destination.cpp \
    radio.cpp \
    source.cpp \
    station.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = QtCoreBeginner
