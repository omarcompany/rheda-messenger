import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

ColumnLayout {
    width: 404
    anchors {
        centerIn: parent
    }
    spacing: 40

    ColumnLayout {
        width: parent.width
        spacing: 20

        LabelField {
            id: title
            height: labelFontPixelSize
            labelFontPixelSize: 48
        }

        LabelField {
            id: text
            height: labelFontPixelSize * 2
            labelText: "Create an account to start messanging"
            labelFontPixelSize: 30
            labelFontBold: false
        }
    }

    ColumnLayout {
        width: parent.width
        spacing: 20

        EntryField {
            id: login
            width: parent.width
            entryFieldTitleText: "Username"
            entryFieldPlaceHolderText: "Введите Username"
        }

        EntryField {
            id: userEmail
            width: parent.width
            entryFieldTitleText: "Email"
            entryFieldPlaceHolderText: "Введите Email"
        }

        PasswordField {
            id: password
            width: parent.width
            passwordFieldTitleText: "Password"
            passwordFieldPlaceHolderText: "Введите пароль"
        }
    }

    ColumnLayout {
        width: parent.width
        spacing: 10

        SimpleButton {
            id: registerButton
            height: 50
            buttonText: "Create account"
            enabled: userEmail.entryFieldText.length && login.entryFieldText.length && password.passwordFieldText.length

            states: [
                State {
                    name: "Registering"
                    PropertyChanges {
                        target: registerButton
                        buttonText: "Registering..."
                        enabled: false
                    }
                }
            ]

            onButtonClicked: {
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
}
