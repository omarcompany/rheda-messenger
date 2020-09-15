import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Control {
    property alias userName: nameText.text
    property alias timestamp: timeText.text
    property alias text: messageText.text

    padding: 12
    width: parent.width

    background: Rectangle {
        color: "#1fe4f2f3"
        radius: 5
        anchors.fill: parent
    }

    contentItem: Column {
        spacing: 10
        Row {
            spacing: 10
            Text {
                id: nameText
                font.bold: true
                font.pixelSize: 14
                text: userName
            }

            Text {
                id: timeText
                anchors.verticalCenter: parent.verticalCenter
                font.italic: true
            }
        }

        Text {
            id: messageText
            width: parent.width
            horizontalAlignment: Text.AlignLeft
            wrapMode: Text.Wrap
            font.pixelSize: 12
        }
    }
}
