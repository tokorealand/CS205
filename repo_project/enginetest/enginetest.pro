TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt


LIBS += -l sqlite3

#LIBS += -pthread

### add the following lines

# if you are having compiler complaints about pthread, uncomment the following
#LIBS += -pthread

SOURCES += ../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../gtest                                   \
                ../gtest/googletest                        \
                ../gtest/googletest/include                \
                ../gtest/googletest/include/gtest

SOURCES += main.cpp\
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
    ../grader/rubricobject.cpp \
    ../grader/rubricsection.cpp\
    ../grader/year.cpp\
    ../grader/semester.cpp



HEADERS  += \
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
    ../grader/rubricobject.cpp \
    ../grader/rubricsection.cpp\
    ../controller/controller.h

