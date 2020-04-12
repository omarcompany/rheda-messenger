import QtQuick 2.0

/*
  * Список контактов.
  * Сверху поле для ввода поискового запроса по контактам.
  * Ниже отображениие всех контактов. Не крадено ни откуда.
  */

Item {
	id: root
	Item {
		id: findBox
		height: 45
		width: parent.width
		anchors.left: parent.left
		anchors.top: parent.top
	}

	ListModel {
		id: testDataModel
		dynamicRoles: true
		Component.onCompleted: {
			for(let i = 0; i <= 15; i++) {
				append({
						   source: "/icons/no_avatar_simple.png",
						   userName: "User Name",
						   lastMessageText: "Last message"
					   })
			}
		}
	}

	ListView {
		height: parent.height - findBox.height
		width: parent.width
		anchors.left: parent.left
		anchors.top: findBox.bottom
		spacing: 2
		model: testDataModel
		clip: true
		delegate: ContactItem {}

	}
}
