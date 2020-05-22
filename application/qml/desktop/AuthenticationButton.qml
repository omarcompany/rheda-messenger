import QtQuick 2.0
import QtQuick.Controls 2.5

MouseArea {
    id: root

    property alias backgroundColor: background.color
    property alias textColor: label.color
    property alias text: label.text
    property alias fontSize: label.font.pixelSize

    property real backgroundOpacity: 0.9
    property int backgroundRadius: 2

    height: background.height

    Rectangle {
        id: background

        height: label.height + 30
        width: parent.width
        color: "#00B4AB"
        opacity: (root.pressed || !root.enabled) ? 0.5 : backgroundOpacity
        radius: backgroundRadius

        Label {
            id: label

            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 20
        }
    }
}
