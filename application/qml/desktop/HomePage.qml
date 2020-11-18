import QtQuick 2.0
import QtQuick.Controls 2.0
import elevons.team 1.0

Page {
    width: parent.width
    height: parent.height

    Timer {
        interval: 60000
        running: true
        repeat: true
        onTriggered: Messenger.requestUserList()
    }

    header: ToolBar {
        position: ToolBar.Header

        Button {
            height: parent.height
            anchors.right: parent.right
            text: qsTr("Sign out")

            onClicked: Messenger.signOut()

            background: Rectangle {
                color: parent.pressed ? "grey" : "skyblue"
            }
        }
    }

    Component.onCompleted: Messenger.requestUserList()

    ListView {
        width: 500
        anchors {
            top: parent.top
            bottom: parent.bottom
        }
        model: ModelProvider.contactModel
        clip: true
        spacing: 1
        delegate: ContactDelegate { }
    }

    footer: Label  {
        text: qsTr("Your ID: %1").arg(Messenger.userId)
    }
}

