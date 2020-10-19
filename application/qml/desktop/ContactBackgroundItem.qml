import QtQuick 2.13
import QtGraphicalEffects 1.12

Rectangle {

    RadialGradient {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "transparent" }
            GradientStop { position: 0.99; color: targetArea.containsMouse ? constants.greenColor :  "transparent"}
        }
    }

    MouseArea {
        id: targetArea
        anchors.fill: parent
        hoverEnabled: true
    }
}
