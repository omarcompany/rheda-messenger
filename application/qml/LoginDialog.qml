import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0


ColumnLayout {
    width: 200
    anchors {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
        margins: 3
    }
    spacing: 10

    TextField {
        id: login
        Layout.fillWidth: true
        placeholderText: "Email"
    }

    TextField {
        id: password
        Layout.fillWidth: true
        placeholderText: "Password"
    }

    CheckBox {
        id: checkBox
        text: qsTr("Remember me")
    }

    Button {
        id: connectButton
        text: "Connect"
        Layout.fillWidth: true

        states: [
            State {
                name: "Connecting"
                PropertyChanges {
                    target: connectButton
                    text: "Connecting..."
                    enabled: false
                }
            }
        ]

        onClicked: {
            connectButton.state = "Connecting"
        }

    }

    Text {
        id: notRegisterLink
        text: qsTr("Not registered?")
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        font.underline: true
        fontSizeMode: Text.Fit
        Layout.fillWidth: false
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        textFormat: Text.AutoText
        font.pixelSize: 12

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: "PointingHandCursor"

            onClicked: {
                main.source = "qrc:/RegistrationDialog.qml"
            }

        }
    }
}
