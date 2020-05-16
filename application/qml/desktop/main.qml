import QtQuick 2.9
import QtQuick.Window 2.2
import elevons.team 1.0

Window {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("Rheda messenger")

    Logotype {
        anchors {
            left: parent.left
            top: parent.top
            margins: 50
        }
    }

	Loader {
        id: mainPageLoader
        anchors.fill: parent
    }

    Component.onCompleted: {
        if (UUIDManager.exists())
            mainPageLoader.source = "qrc:/HomePage.qml"
        else
            mainPageLoader.source = "qrc:/AuthenticationPage.qml"
    }
}
