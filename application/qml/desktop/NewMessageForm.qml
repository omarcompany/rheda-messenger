import QtQuick 2.5
import elevons.team 1.0
import QtQuick.Controls 2.5


Row {
    Column {
        width: parent.width - sendMessageButton.width

        TextField {
            id: recipientField
            width: parent.width
            font.pixelSize: 11
            placeholderText: qsTr("Enter recipient id...")
            placeholderTextColor: "#00B4AB"
            selectByMouse: true
        }

        TypingArea {
            id: typingArea
            height: 60
            width: parent.width
            pointSize: 11
            placeholderTextColor: "#00B4AB"
            borderColor: "#21be2b"
        }
    }

    RoundButton {
        id: sendMessageButton
        anchors.verticalCenter: parent.verticalCenter
        radius: 5
        text: qsTr("Send message")
        enabled: recipientField.text !== "" && typingArea.message !== ""
        onClicked: {
            Messenger.sendMessage(recipientField.text, typingArea.message)
            typingArea.clear()
        }
    }
}


