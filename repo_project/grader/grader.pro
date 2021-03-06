TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle



CONFIG += qt

LIBS += -l sqlite3

SOURCES += main.cpp \
    grader.cpp \
    student.cpp \
    lab.cpp \
    section.cpp \
    dbtable.cpp \
    dbtool.cpp \
    class.cpp \
    ../controller/controller.cpp \
    fileparser.cpp \
    component.cpp \
    comment.cpp \
    rubricobject.cpp \
    year.cpp \
    semester.cpp \
    rubricsection.cpp

HEADERS += \
    grader.h \
    student.h \
    lab.h \
    section.h \
    dbtable.h \
    dbtool.h \
    class.h \
    ../controller/controller.h \
    fileparser.h \
    component.h \
    comment.h \
    rubricobject.h \
    year.h \
    semester.h \
    rubricsection.h

