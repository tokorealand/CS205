TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -l sqlite3

SOURCES += main.cpp\
    ../grader/student.cpp \
    ../grader/lab.cpp \
    ../grader/section.cpp \
    ../grader/dbtable.cpp \
    ../grader/dbtool.cpp \
    ../grader/class.cpp \
    ../grader/component.cpp \
    ../grader/comment.cpp\
../grader/year.cpp\
../grader/semester.cpp\
    exporter.cpp



HEADERS  += ../grader/student.h \
    ../grader/lab.h \
    ../grader/section.h \
    ../grader/dbtable.h \
    ../grader/dbtool.h \
    ../grader/class.h \
    ../grader/component.h \
../grader/year.h\
../grader/semester.h\
    ../grader/comment.h\
exporter.h
