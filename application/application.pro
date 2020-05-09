TEMPLATE = app

TARGET = rheda-messenger

QT += quick network

CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
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

INCLUDEPATH += src

HEADERS += \
	src/requester.h \
        src/uuidmanager.h \
        src/messenger.h \
        src/serializer.h
