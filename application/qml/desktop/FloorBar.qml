import QtQuick 2.13
import elevons.team 1.0

Rectangle {
    id: root

    Text {
        anchors {
             verticalCenter: parent.verticalCenter
             left: parent.left
             leftMargin: 5
        }

        text: qsTr("Your ID: %1").arg(Messenger.userId)
    }
}
