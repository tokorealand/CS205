#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T03:46:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = add_students_gui
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

LIBS += -l sqlite3

SOURCES += main.cpp\
        add_students_gui.cpp\
    ../grader/student.cpp \
    ../grader/lab.cpp \
    ../grader/section.cpp \
    ../grader/dbtable.cpp \
    ../grader/dbtool.cpp \
    ../grader/commentengine.cpp \
    ../grader/class.cpp \
    ../grader/component.cpp \
    ../controller/controller.cpp\
    ../grader/grader.cpp\
    ../grader/comment.cpp\
    ../grader/fileparser.cpp\
../grader/year.cpp\
../grader/semester.cpp\
    ../grader/rubricobject.cpp

HEADERS  += add_students_gui.h\
    ../grader/student.h \
    ../grader/lab.h \
    ../grader/section.h \
    ../grader/dbtable.h \
    ../grader/dbtool.h \
    ../grader/commentengine.h \
    ../grader/class.h \
    ../grader/component.h \
    ../controller/controller.h\
    ../grader/grader.h\
    ../grader/comment.h\
../grader/year.h\
../grader/semester.h\
    ../grader/fileparser.h\
    ../grader/rubricobject.h


FORMS    += add_students_gui.ui
