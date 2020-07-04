import QtQuick 2.0
import elevons.team 1.0
import QtQuick.Controls 2.0

Item {
    width: parent.width
    height: parent.height

    Text {
        id: name
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            margins: 100
        }

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
            Messenger.signOut();
        }
    }

    FloorBar {
        height: 15
        width: parent.width
        anchors.bottom: parent.bottom
    }

    NewMessageForm {
        width: parent.width*0.75
        anchors.centerIn: parent
    }
}
