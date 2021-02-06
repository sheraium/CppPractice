SOURCES += xsocket.cpp
HEADERS += xsocket.h \
           xglobal.h

TEMPLATE = lib
DEFINES += LIBDLL_LIB
#CONFIG += staticlib

TARGET = libdll
DESTDIR = ./bin
#DLLDESTDIR = ./lib
