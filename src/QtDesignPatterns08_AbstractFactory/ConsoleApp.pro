QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \
    cats/catfactory.cpp \
    cats/housecat.cpp \
    cats/bobcat.cpp \
    cats/lion.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    cats/catfactory.h \
    cats/housecat.h \
    cats/bobcat.h \
    cats/lion.h \
    interfaces/ianimal.h \
    interfaces/ianimalfactory.h
