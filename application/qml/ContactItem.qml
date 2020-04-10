import QtQuick 2.0

Rectangle {
	id: root

	height: 70
	width: parent.width
	color: "transparent"
	radius: 2
	border.color: "lightgray"

	Row {
		anchors.fill: parent

		Rectangle {
			id: userAvatarArea
			height: parent.height
			width: height
			color: "transparent"

			Image {
				anchors.centerIn: parent.center
				anchors.verticalCenter: parent.verticalCenter
				sourceSize.height: parent.height - 4
				sourceSize.width: parent.width - 4
				fillMode: Image.PreserveAspectFit
				source: model.source
			}
		}

		Column {
			id: usernameAndLastmessage
			width: parent.width - userAvatarArea.width - 10

			Rectangle {
				id: userNameArea
				height: root.height / 2
				width: parent.width
				color: "transparent"

				Text {
					anchors.verticalCenter: parent.verticalCenter
					text: qsTr(model.userName)
				}
			}

			Rectangle {
				id: lastMessageArea
				height: root.height / 2
				width: parent.width
				color: "transparent"

				Text {
					anchors.verticalCenter: parent.verticalCenter
					text: qsTr(model.lastMessageText)
				}
			}
		}
	}
}
