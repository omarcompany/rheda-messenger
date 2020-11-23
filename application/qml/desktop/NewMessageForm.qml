import QtQuick 2.5
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import elevons.team 1.0

RowLayout {
    TypingArea {
        id: typingArea
        height: 60
        width: parent.width - button.width
        pointSize: 11
        placeholderTextColor: "#00B4AB"
        borderColor: "#21be2b"
        Layout.fillWidth: true
        Layout.columnSpan: 2
        Layout.row: 1
    }

    RoundButton {
        id: button
        radius: 5
        text: qsTr("Send message")
        enabled: typingArea.message !== ""
        onClicked: {
            Messenger.sendMessage(recipientID, typingArea.message)
            typingArea.clear()
        }
    }
}


