import QtQuick 2.0
import elevons.team 1.0
import QtQuick.Controls 2.0

Item {
    width: parent.width
    height: parent.height

    Text {
        id: name
        anchors.centerIn: parent
        font.pixelSize: 40
        text: qsTr("Welcome to rheda messenger!")
    }

    Button {
        anchors {
            right: parent.right
            top: parent.top
            margins: 50
        }
        text: qsTr("Sign out")
        onClicked: {
            UUIDManager.clear()
            mainPageLoader.source = "qrc:/AuthenticationPage.qml"
        }
    }
}
