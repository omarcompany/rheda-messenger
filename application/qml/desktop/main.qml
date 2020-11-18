import QtQuick 2.9
import QtQuick.Window 2.2
import elevons.team 1.0

Window {
    id: window
    visible: true
    width: 1440
    height: 1024
    title: qsTr("Rheda messenger")
    minimumWidth: 480
    minimumHeight: 720

    property bool signed: Messenger.userId !== ""

    QtObject {
        id: constants
        readonly property string registrationText: qsTr("Create an account to start messanging")
        readonly property string greenColor : "#4DA7B0"
    }

    Loader {
        anchors.fill: parent
        source: signed ? "qrc:/HomePage.qml" : "qrc:/AuthenticationPage.qml"
    }
}
