import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Control {

    property alias userName: nameText.text
    property alias timestamp: timeText.text
    property alias text: messageText.text

    padding: 10

    background: Rectangle {
        border {
            width: 1
            color: "#00B4AB"
        }
    }

    contentItem: GridLayout {
        width: parent.width
        columns: 3
        rows: 2
        Text {
            id: nameText
        }
        Item {
            Layout.fillWidth: true
        }
        Text {
            id: timeText
        }

        Text {
            id: messageText
            Layout.columnSpan: 3
        }
    }
}
