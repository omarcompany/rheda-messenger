TEMPLATE = app

TARGET = rheda-messenger

QT += quick sql network

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
	src/databaseengine.cpp \
	src/main.cpp \
	src/requester.cpp \
	src/uuidmanager.cpp \
	src/messenger.cpp \
	src/serializer.cpp

RESOURCES += qml/desktop/qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

android: include($$(HOME)/Android/Sdk/android_openssl/openssl.pri)

INCLUDEPATH += src

HEADERS += \
	src/databaseengine.h \
	src/message.h \
	src/requester.h \
	src/messenger.h \
	src/serializer.h \
	src/user.h \
	src/uuidmanager.h
