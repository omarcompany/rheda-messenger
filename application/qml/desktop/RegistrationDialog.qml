import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import elevons.team 1.0

ColumnLayout {
    width: 404
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
    }

    ColumnLayout {
        width: parent.width
        spacing: 10

        SimpleButton {
            id: registerButton
            height: 50
            buttonText: "Create account"
            enabled: login.entryFieldText.length

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
                Messenger.signUp(login.entryFieldText)
            }
        }

//        Text {
//            text: qsTr("Already registered")
//            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
//            font.underline: true
//            font.pixelSize: 12

//            MouseArea{
//                anchors.fill: parent
//                hoverEnabled: true
//                cursorShape: "PointingHandCursor"

//                onClicked: authenticationLoader.source = "qrc:/LoginDialog.qml"
//            }
//        }
    }

    Connections {
        target: Messenger
        onSignUpComplete: {
            mainPageLoader.source = "qrc:/HomePage.qml"
        }
        onError: {
            switch (errorType) {
            case Messenger.NoNetWorkConnect:
                text.labelText = qsTr("Host not found or no network connection")
                break
            case Messenger.NotFound:
                text.labelText = qsTr("404:The server cannot process the request")
                break
            case Messenger.ServerNotAvailable:
                text.labelText = qsTr("503:Server is not available")
                break
            }
        }
    }
}

