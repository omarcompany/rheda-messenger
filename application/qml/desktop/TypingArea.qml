import QtQuick 2.0
import QtQuick.Controls 2.5

Flickable {
    property alias message: textArea.text
    property alias pointSize: textArea.font.pointSize
    property alias placeholderTextColor: textArea.placeholderTextColor
    property string borderColor

    function clear() {
        message = ""
    }

    TextArea.flickable: TextArea  {
        id: textArea
        placeholderText:  qsTr("Message text...")
        font.family: "Helvetica"
        focus: true
        wrapMode: TextEdit.Wrap
        selectByMouse: true

        background: Rectangle {
            implicitWidth: parent.width
            implicitHeight: parent.height
            border.color: borderColor
        }
    }

    ScrollBar.vertical: ScrollBar { }
}

