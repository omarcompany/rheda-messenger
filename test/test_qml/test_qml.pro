TEMPLATE = app

TARGET = rheda-test-qml

CONFIG += warn_on qmltestcase

PATH_APP = ../../application/src
INCLUDEPATH += $$PATH_APP

HEADERS += \
    $$PATH_APP/messagemodel.h \
    test_message_model.h

SOURCES += \
    $$PATH_APP/messagemodel.cpp \
    test_message_model.cpp

DISTFILES += *.qml
