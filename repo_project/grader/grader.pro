TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    grader.cpp \
    student.cpp \
    lab.cpp \
    section.cpp

HEADERS += \
    grader.h \
    student.h \
    lab.h \
    section.h
