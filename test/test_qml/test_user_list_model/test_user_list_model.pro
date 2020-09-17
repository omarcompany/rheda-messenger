include(../test_qml_base.pri)
include(test_UserList_model_files.pri)

TEMPLATE = app

TARGET = test-user-list-model

SOURCES += \
    test_user_list_model.cpp

DISTFILES += *.qml

HEADERS += \
    test_user_list_model.h
