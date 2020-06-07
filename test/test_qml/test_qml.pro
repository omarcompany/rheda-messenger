TEMPLATE = app

TARGET = rheda-test-qml

CONFIG += warn_on qmltestcase

PATH_APP = ../../application/src
INCLUDEPATH += $$PATH_APP

HEADERS += \
    testcase.h

SOURCES += \
    testcase.cpp

DISTFILES += *.qml
