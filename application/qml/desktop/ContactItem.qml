import QtQuick 2.13
import QtQuick.Controls 2.0

Rectangle {
    property alias text: label.text
    property alias horizontalAlignment: label.horizontalAlignment

    color: "transparent"

    Label {
        id: label
        width: parent.width
        font.pixelSize: 20
        anchors.verticalCenter: parent.verticalCenter
    }
}
