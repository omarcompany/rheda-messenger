import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

ColumnLayout {
    property string entryFieldColor: "#00B4AB"
    property string entryFieldPlaceHolderText
    property string entryFieldTitleText
    property string entryFieldText: textField.text
    property string entryFieldStyleName: "Roboto"
    property int entryFieldFontPixelSize: 18
    property int entryFieldLineSize: parent.width
    property int entryFieldEchoMode: TextInput.Normal

    property alias text: textField.text

    id: root
    spacing: 10

    Label {
        id: label
        width: parent.width
        height: entryFieldFontPixelSize
        color: entryFieldColor
        text: entryFieldTitleText
        font {
            pixelSize: entryFieldFontPixelSize
            styleName: entryFieldStyleName
        }
    }

    TextField {
        id: textField
        width: parent.width
        font.pixelSize: entryFieldFontPixelSize
        echoMode: entryFieldEchoMode
        placeholderTextColor: entryFieldColor
        placeholderText: entryFieldPlaceHolderText
        color: entryFieldColor

        background: Item {
            implicitWidth: parent.width
            implicitHeight: parent.height

            Rectangle {
                color: entryFieldColor
                height: 1
                width: entryFieldLineSize
                opacity: 0.5
                anchors.bottom: parent.bottom
            }
        }
    }
}
