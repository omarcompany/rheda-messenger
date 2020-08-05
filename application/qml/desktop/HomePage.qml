import QtQuick 2.0
import QtQuick.Controls 2.0
import elevons.team 1.0

Page {
    width: parent.width
    height: parent.height

    header: Label {
        padding: 20
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 40
        text: qsTr("Welcome to rheda messenger!")

        Button {
            anchors {
                right: parent.right
                rightMargin: 50
                verticalCenter: parent.verticalCenter
            }
            text: qsTr("Sign out")
            onClicked: {
                Messenger.signOut();
            }
        }
    }

    padding: 10
    contentItem: MessageList {
        model: ModelProvider.messageList
    }

    footer: Control {
        padding: 10
        contentItem: Column {
            spacing: 10
            NewMessageForm {
                width: parent.width*0.75
            }

            FloorBar {}
        }
    }
}
