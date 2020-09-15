import QtQuick 2.0
import QtQuick.Controls 2.0
import elevons.team 1.0

Page {
    id: root
    anchors.fill: parent

    property int contactBoxWidth: 400

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
    contentHeight: parent.height
    contentWidth: parent.width

    contentItem: Row {
        spacing: 5
        ContactList {
            id: contactList
            width: 400
            height: parent.height
        }

        Column {
            height: parent.height
            MessageList {
                height: parent.height - newMessageForm.height
                width: root.width - contactList.width - 20
            }

            NewMessageForm {
                id: newMessageForm
                width: root.width - contactList.width - 20
            }
        }
    }

    Component.onCompleted: Messenger.requestMessageList(Messenger.userId)

    //    footer: Control {
    //        padding: 10
    //        contentItem: Column {
    //            spacing: 10
    //            NewMessageForm {
    //                width: parent.width * 0.75
    //            }

    //            FloorBar {}
    //        }
    //    }
}
