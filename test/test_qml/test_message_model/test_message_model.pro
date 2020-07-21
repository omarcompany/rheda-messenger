include(../test_qml_base.pri)
include(test_message_model_files.pri)

TEMPLATE = app

TARGET = test-message-model

HEADERS += \
    test_message_model.h

SOURCES += \
    test_message_model.cpp

DISTFILES += *.qml
