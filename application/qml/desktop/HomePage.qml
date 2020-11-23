import QtQuick 2.0
import QtQuick.Controls 2.0
import elevons.team 1.0
import QtQuick.Layouts 1.12

Page {
    id:root
    width: parent.width
    height: parent.height
    property string recipientID
    property string recipientName

    Component.onCompleted: Messenger.requestUserList()

    Timer {
        interval: 60000
        running: true
        repeat: true
        onTriggered : Messenger.requestUserList()
    }

    Timer {
        interval: 6000
        running: true
        repeat: true
        onTriggered : Messenger.requestMessageList()
    }

    GridLayout {
        anchors.fill: parent
        columns: 2
        rows: 3

        Rectangle {
            id:searchField
            width: 500
            height: 82
            Layout.row: 1
            Layout.column: 1
            Button {
                height: parent.height
                anchors.left: parent.left
                text: qsTr("Sign out")

                onClicked: Messenger.signOut()

                background: Rectangle {
                    color: parent.pressed ? "grey" : "skyblue"
                }
            }
        }

        ListView {
            width: searchField.width
            Layout.rowSpan: 2
            Layout.row: 2
            Layout.column: 1
            Layout.fillHeight: true
            model: ModelProvider.contactModel
            clip: true
            spacing: 1
            delegate: ContactDelegate {
                onLeftClicked: {
                    recipientID = model.id
                    recipientName = model.name
                }
            }
        }

        Rectangle {
            Layout.row: 1
            Layout.column: 2
            Layout.fillWidth: true
            height: searchField.height

            ChatTitle {
                anchors {
                    left: parent.left
                    leftMargin: 24
                    verticalCenter: parent.verticalCenter
                }
            }
        }

        MessageList {
            Layout.row: 2
            Layout.column: 2
            Layout.fillWidth: true
            Layout.fillHeight: true

            model: ModelProvider.messageList
        }

        NewMessageForm {
            Layout.row: 3
            Layout.column: 2
            Layout.illWidth: true
            Layout.fillHeight: true

        }
    }

    footer: Label  {
        text: qsTr("Your ID: %1").arg(Messenger.userId)
    }
}
