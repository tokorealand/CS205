TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    exporter.cpp \
    ../grader/lab.cpp \
    ../grader/comment.cpp

HEADERS += \
    exporter.h \
    ../grader/lab.h \
    ../grader/comment.h

