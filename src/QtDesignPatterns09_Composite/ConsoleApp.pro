QT += widgets
INCLUDEPATH += $$PWD/../../include
#LIBS += -L../../lib -l

#HEADERS += \

SOURCES += main.cpp \
    school.cpp \
    student.cpp \
    teacher.cpp

CONFIG += console
#CONFIG += staticlib
#TEMPLATE = lib

DESTDIR += ./bin
TARGET = ConsoleApp

HEADERS += \
    school.h \
    student.h \
    teacher.h
