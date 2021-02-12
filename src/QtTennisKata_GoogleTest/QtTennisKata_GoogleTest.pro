include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

HEADERS += \
        tennis.h \
        tst_tennistestcase.h

SOURCES += \
        main.cpp \
        tennis.cpp
