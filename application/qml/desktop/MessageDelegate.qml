import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12

Control {
    id: message

    property string user_name
    property string timestamp
    property string text

    width: Math.min(parent.width, 400)

    padding: 10

    background: Rectangle {
        border {
            width: 1
            color: "#00B4AB"
        }
    }

    contentItem: GridLayout {
        id: grid
        width: parent.width
        columns: 3
        rows: 2
        Text {
            text: message.user_name
        }
        Item {
            Layout.fillWidth: true
        }
        Text {
            text: message.timestamp
        }

        Text {
            text: message.text
            Layout.columnSpan: 3
        }
    }
}
