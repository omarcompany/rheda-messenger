TEMPLATE = app

TARGET = rheda-test-cpp

QT += testlib sql network
CONFIG += qt console warn_on depend_includepath testcase

PATH_APP = ../../application/src
INCLUDEPATH += $$PATH_APP

HEADERS += \
    testcase.h \
    $$PATH_APP/databaseengine.h \
    $$PATH_APP/serializer.h

SOURCES += \
    testcase.cpp \
    $$PATH_APP/databaseengine.cpp \
    $$PATH_APP/serializer.cpp

DEFINES += PRO_FILE_PWD=$$sprintf("\"\\\"%1\\\"\"", $$_PRO_FILE_PWD_)

DISTFILES += \
	test_messages.json \
	test_user.json
