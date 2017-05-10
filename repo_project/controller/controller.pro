TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -l sqlite3


HEADERS += \
    ../grader/student.h \
    ../grader/lab.h \
    ../grader/section.h \
    ../grader/dbtable.h \
    ../grader/dbtool.h \
    ../grader/class.h \
    ../grader/component.h \
../grader/comment.h\
../grader/year.h\
../grader/semester.h\
../grader/rubricsection.h\
    controller.h \
    ../grader/rubricobject.h



SOURCES += main.cpp \
    ../grader/student.cpp \
    ../grader/lab.cpp \
    ../grader/section.cpp \
    ../grader/dbtable.cpp \
    ../grader/dbtool.cpp \
    ../grader/class.cpp \
    ../grader/component.cpp \
    ../grader/comment.cpp\
    controller.cpp \
../grader/rubricsection.cpp\
../grader/year.cpp\
../grader/semester.cpp\
    ../grader/rubricobject.cpp




