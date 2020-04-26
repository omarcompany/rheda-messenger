import QtQuick 2.0

Item {
    signal buttonPressed()
    signal buttonReleased()

    property real iconButtonOpacity: 1
    property string iconButtonSource

    Image {
        id: icon
        anchors.fill: parent
        source: iconButtonSource
        opacity: mouseArea.pressed ? 0.3 : iconButtonOpacity
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onPressed: buttonPressed()
        onReleased: buttonReleased()
    }
}
