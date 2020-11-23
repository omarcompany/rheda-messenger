import QtQuick 2.0
import QtQuick.Layouts 1.12

Row {
    spacing: 7

    ContactItem {
        width: 44
        height: 47
        border.color: constants.greenColor
        horizontalAlignment: Text.AlignHCenter
        text: recipientName[0]
    }

    ContactItem {
        width: 420
        height: 17
        text: recipientName
        anchors {
            top: parent.top
            topMargin: 13
        }
    }
}
