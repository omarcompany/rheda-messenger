import QtQuick 2.13

ContactBackgroundItem {
    width: row.width
    height: row.height
    border.color: constants.greenColor

    Row {
        id: row
        spacing: 8
        topPadding: 2
        bottomPadding: 2
        anchors {
            left: parent.left
            leftMargin: 10
            verticalCenter:parent.verticalCenter

        }
        ContactItem {
            width: 71
            height: 71
            radius: 100
            border.color: constants.greenColor
            horizontalAlignment: Text.AlignHCenter
            text: model.name[0]
        }

        ContactItem {
            width: 420
            height: 17
            text: model.name
            anchors {
                top: parent.top
                topMargin: 13
            }
        }
    }
}
