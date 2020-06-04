TEMPLATE = app
TARGET = rheda-messenger-tests
QT += testlib sql
CONFIG += qt console warn_on depend_includepath testcase

PATH_APP = ../application/src
INCLUDEPATH += $$PATH_APP

HEADERS += \
    $$PATH_APP/databaseengine.h \
    $$PATH_APP/user.h \
    testcase.h

SOURCES += \
    $$PATH_APP/databaseengine.cpp \
    testcase.cpp
