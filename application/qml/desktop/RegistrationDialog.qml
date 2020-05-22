import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import elevons.team 1.0

Column {
    spacing: 30

    Column {
        InformationLabel {
            text: qsTr("Hello!")
            font.pixelSize: 48
            font.bold: true
        }

        InformationLabel {
            id: mainInformationLabel
            text: textMainIformation
            font.pixelSize: 30
            width: registrationButton.width
            errorHighlighted: errorState
        }
    }

    Column {
        width: parent.width
        spacing: 10

        EntryField {
            id: login
            width: registrationButton.width
            entryFieldTitleText: qsTr("Username")
            entryFieldPlaceHolderText: qsTr("Enter the username")
            enabled: !errorState
        }

        AuthenticationButton {
            id: registrationButton

            width: minimumWidth - 80

            onClicked: {
                switch (state) {
                case "Default":
                    Messenger.signUp(login.entryFieldText)
                    state = "Waiting"
                    break
                case "Error":
                    textMainIformation = constants.registrationText
                    errorState = false
                    login.text = ""
                    state = "Default"
                }
            }

            state: "Default"

            states: [ State {
                    name: "Default"
                    PropertyChanges {
                        target: registrationButton
                        text: qsTr("Create account")
                        enabled: login.entryFieldText.length
                    }
                },
                State {
                    name: "Waiting"
                    PropertyChanges {
                        target: registrationButton
                        text: qsTr("Registering...")
                        enabled: false
                    }
                },
                State {
                    name: "Error"
                    when: errorState
                    PropertyChanges {
                        target: registrationButton
                        text: qsTr("Retry")
                        enabled: true
                    }
                }
            ]
        }

        Text {
            text: qsTr("Already registered")
            anchors.horizontalCenter: parent.horizontalCenter
            font.underline: true
            font.pixelSize: 12
            visible: false

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: "PointingHandCursor"

                onClicked: authenticationLoader.source = "qrc:/LoginDialog.qml"
            }
        }
    }
}

