import QtQuick 2.9
import QtQuick.Window 2.2
import elevons.team 1.0

Window {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("Rheda messenger")
    minimumWidth: 480
    minimumHeight: 720

    property bool signed: Messenger.userId !== ""

    QtObject {
        id: constants
        readonly property string registrationText: qsTr("Create an account to start messanging")
    }

    Logotype {
        anchors {
            left: parent.left
            top: parent.top
            margins: 50
        }
    }

    Loader {
        anchors.fill: parent
        source: signed ? "qrc:/HomePage.qml" : "qrc:/AuthenticationPage.qml"
    }
}
