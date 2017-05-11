#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T22:08:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -l sqlite3
TARGET = RubricCreatorGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        rubriccreatorgui.cpp \
    ../grader/student.cpp \
    ../grader/lab.cpp \
    ../grader/section.cpp \
    ../grader/dbtable.cpp \
    ../grader/dbtool.cpp \
    ../grader/class.cpp \
    ../grader/component.cpp \
    ../grader/grader.cpp\
    ../grader/fileparser.cpp \
    ../controller/controller.cpp \
    ../grader/comment.cpp \
../grader/year.cpp\
../grader/semester.cpp\
../grader/rubricsection.cpp\
    ../grader/rubricobject.cpp

HEADERS  += rubriccreatorgui.h \
    ../grader/student.h \
    ../grader/lab.h \
    ../grader/section.h \
    ../grader/dbtable.h \
    ../grader/dbtool.h \
    ../grader/class.h \
    ../grader/component.h \
    ../grader/grader.h\
../grader/year.h\
../grader/semester.h\
    ../grader/fileparser.h\
    ../controller/controller.h \
    ../grader/comment.h \
../grader/rubricsection.h\
    ../grader/rubricobject.h

FORMS    += rubriccreatorgui.ui
