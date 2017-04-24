#-------------------------------------------------
#
# Project created by QtCreator 2017-04-23T20:05:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RubricGUI
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
        rubricgui.cpp\
    ../grader/student.cpp \
    ../grader/lab.cpp \
    ../grader/section.cpp \
    ../grader/dbtable.cpp \
    ../grader/dbtool.cpp \
    ../grader/commentengine.cpp \
    ../grader/class.cpp \
    ../grader/component.cpp \
    ../grader/grader.cpp \
    ../grader/fileparser.cpp \
    ../grader/comment.cpp\
    ../controller/controller.cpp\
    ../addlabsGUI/addlabsgui.cpp\
    ../grader/year.cpp\
    ../grader/semester.cpp\
    ../CommentGUI/dialog.cpp \
    ../RubricCreatorGUI/rubriccreatorgui.cpp \
    ../grader/rubricsection.cpp\
    ../grader/rubricobject.cpp

HEADERS  += rubricgui.h\
    ../grader/student.h \
    ../grader/lab.h \
    ../grader/section.h \
    ../grader/dbtable.h \
    ../grader/dbtool.h \
    ../grader/commentengine.h \
    ../grader/class.h \
    ../grader/component.h \
    ../grader/grader.cpp \
    ../grader/comment.h\
    ../grader/fileparser.h \
    ../grader/year.h\
    ../grader/semester.h\
    ../grader/comment.h\
    ../controller/controller.h\
    ../addlabsGUI/addlabsgui.h \
    ../CommentGUI/dialog.h \
    ../RubricCreatorGUI/rubriccreatorgui.h \
    ../grader/rubricsection.h\
    ../grader/rubricobject.h


FORMS    += rubricgui.ui
