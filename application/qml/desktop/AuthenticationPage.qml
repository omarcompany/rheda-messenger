import QtQuick 2.0

Item {
    anchors.fill: parent

    Logotype {
        anchors {
            left: parent.left
            top: parent.top
            margins: 50
        }
    }

    Loader {
        id: authenticationLoader
        anchors.centerIn: parent
    }

    Component.onCompleted: {
        authenticationLoader.source = "qrc:/RegistrationDialog.qml"
    }
}
