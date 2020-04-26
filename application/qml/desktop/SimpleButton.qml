import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    signal buttonClicked()

    property string buttonBackgroundColor: "#00B4AB"
    property string buttonTextColor: "white"
    property real buttonBackgroundOpacity: 0.9
    property string buttonText: "Я тут"
    property int buttonTextFontPixelSize: 20
    property bool buttonEnabled: true
    property int buttonRadius: 2

    id: button
    width: parent.width

    Rectangle {
        id: background
        anchors.fill: parent
        color: buttonBackgroundColor
        opacity: (mouseArea.pressed || !button.enabled)  ? 0.5 : buttonBackgroundOpacity
        radius: buttonRadius
    }

    Text {
        anchors.centerIn: parent
        text: buttonText
        color: buttonTextColor
        font {
            pixelSize: buttonTextFontPixelSize
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: background
        enabled: buttonEnabled
        onClicked: buttonClicked()
    }
}
