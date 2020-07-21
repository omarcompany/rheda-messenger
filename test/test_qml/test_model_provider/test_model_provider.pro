include(../test_qml_base.pri)
include(../test_message_model/test_message_model_files.pri)

TEMPLATE = app

TARGET = test-model-provider

HEADERS += \
    $$PATH_APP/modelprovider.h \
    test_model_provider.h

SOURCES += \
    $$PATH_APP/modelprovider.cpp \
    test_model_provider.cpp

DISTFILES += *.qml
