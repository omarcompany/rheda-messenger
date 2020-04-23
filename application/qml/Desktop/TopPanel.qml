import QtQuick 2.0

Item {
    id: topPanel
    width: parent.width
    height: 90
    anchors.top: parent.top

    Image {
        id: icon
        anchors.bottom: parent.bottom
        x: parent.width / 20
        source: "qrc:/icons/Title.svg"
    }
}

