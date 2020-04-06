import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0


ColumnLayout {
    width: 220
    height: 77
    anchors {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
        margins: 3
    }
    spacing: 10

    TextField {
        id: userEmail
        text: ""
        inputMask: qsTr("")
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

}
