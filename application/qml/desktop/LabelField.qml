import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    property string labelStyleName: "Roboto"
    property int labelFontPixelSize: 40
    property bool labelFontBold: true
    property string labelFontColor: "#00B4AB"
    property string labelText: "Hello!"

    width: parent.width

    Label {
        id: title
        width: parent.width
        text: labelText
        color: labelFontColor
        font {
            bold: labelFontBold
            styleName: labelStyleName
            pixelSize: labelFontPixelSize

        }
        maximumLineCount: 2
        elide: Text.ElideRight
        wrapMode: Text.Wrap
    }
}

