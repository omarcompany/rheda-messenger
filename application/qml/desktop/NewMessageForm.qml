import QtQuick 2.5
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
import elevons.team 1.0

GridLayout {
    columns: 2
    rows: 2

    TextField {
        id: recipientField
        font.pixelSize: 11
        placeholderText: qsTr("Enter recipient id...")
        placeholderTextColor: "#00B4AB"
        selectByMouse: true
        Layout.fillWidth: true
    }

    RoundButton {
        radius: 5
        text: qsTr("Send message")
        enabled: recipientField.text !== "" && typingArea.message !== ""
        onClicked: {
            Messenger.sendMessage(recipientField.text, typingArea.message)
            typingArea.clear()
        }
    }

    TypingArea {
        id: typingArea
        height: 60
        width: parent.width
        pointSize: 11
        placeholderTextColor: "#00B4AB"
        borderColor: "#21be2b"
        Layout.fillWidth: true
        Layout.columnSpan: 2
        Layout.row: 1
    }

}


