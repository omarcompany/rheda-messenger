import QtQuick 2.0
import elevons.team 1.0

Item {
    property string textMainIformation: constants.registrationText
    property bool errorState

    anchors.fill: parent

    Logotype {
        anchors {
            left: parent.left
            top: parent.top
            margins: 50
        }
    }

    Loader {
        anchors.centerIn: parent
        source: "qrc:/RegistrationDialog.qml"
    }

    Connections {
        target: Messenger
        onError: {
            errorState = true

            switch (errorType) {
            case Messenger.NoNetWorkConnect:
                textMainIformation = qsTr("Host not found or no network connection")
                break
            case Messenger.NotFound:
                textMainIformation = qsTr("404:The server cannot process the request")
                break
            case Messenger.ServerNotAvailable:
                textMainIformation = qsTr("503:Server is not available")
                break
            }
        }
    }
}
