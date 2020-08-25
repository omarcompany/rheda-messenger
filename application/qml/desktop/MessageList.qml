import QtQuick 2.0

ListView {

    spacing: 10
    clip: true

    delegate: MessageDelegate {
        width: Math.min(ListView.view.width, 400)

        userName: model.name ? model.name : "ID: " + model.id.slice(0,10)
        timestamp: model.timestamp
        text: model.text
    }
}
