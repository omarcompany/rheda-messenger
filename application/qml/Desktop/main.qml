import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("Rheda messenger")

    TopPanel {
        id: topPanel
    }

//	ContactList {
//		id: contactList
//		height: parent.height
//		width: 400
//		anchors.left: parent.left
//	}

	Loader {
		id: dialogLoader
		anchors.centerIn: parent
		source: "qrc:/LoginDialog.qml"
	}
}
