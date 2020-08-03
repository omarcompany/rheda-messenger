import QtQuick 2.0

ListView {

    spacing: 10
    clip: true

    delegate: MessageDelegate {
        width: Math.min(ListView.view.width, 400)

        userName: model.name
        timestamp: model.timestamp
        text: model.text
    }
}
