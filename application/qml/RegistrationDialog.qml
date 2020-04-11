import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0


ColumnLayout {
    width: 220
    anchors {
        centerIn: parent
    }
    spacing: 10

    TextField {
        id: userEmail
        Layout.fillWidth: true
        placeholderText: "Email"
    }

    TextField {
        id: password
        Layout.fillWidth: true
        placeholderText: "Password"
        echoMode: TextInput.PasswordEchoOnEdit
    }

    TextField {
        id: login
        Layout.fillWidth: true
        placeholderText: "Username"
    }

    Button {
        id: registerButton
        Layout.fillWidth: true
        enabled: userEmail.text.length && login.text.length && password.text.length
        text: "Register"

        states: [
            State {
                name: "Registering"
                PropertyChanges {
                    target: registerButton
                    text: "Registering..."
                    enabled: false
                }
            }
        ]

        onClicked: {
            registerButton.state = "Registering"
        }
    }

    Text {
        text: qsTr("Already registered")
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        font.underline: true
        font.pixelSize: 12

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: "PointingHandCursor"

            onClicked: dialogLoader.source = "qrc:/LoginDialog.qml"
        }
    }
}
