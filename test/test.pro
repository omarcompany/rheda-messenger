TEMPLATE = app
TARGET = rheda-messenger-tests
QT += testlib
CONFIG += qt console warn_on depend_includepath testcase

INCLUDEPATH += $$PATH_APP

HEADERS += \
    testcase.h

SOURCES += \
    testcase.cpp

DISTFILES += \
    files.desktop \
    rpm/files.spec
