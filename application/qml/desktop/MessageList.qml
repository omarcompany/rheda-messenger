import QtQuick 2.0
import elevons.team 1.0

ListView {
    id: view
    model: ModelProvider.messageList
    spacing: 10

    delegate: MessageDelegate {
        user_name: model.name
        timestamp: model.timestamp
        text: model.text
    }
}
