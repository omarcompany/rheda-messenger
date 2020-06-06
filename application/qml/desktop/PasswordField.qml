import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    property string passwordFieldColor: "#00B4AB"
    property string passwordFieldTitleText: "Password"
    property string passwordFieldFontStyleName: "Roboto"
    property string passwordFieldPlaceHolderText
    property string passwordFieldText: entryField.entryFieldText

    height: entryField.height
    width: parent.width

    EntryField {
        id: entryField
        entryFieldColor: passwordFieldColor
        entryFieldPlaceHolderText: passwordFieldPlaceHolderText
        entryFieldTitleText: passwordFieldTitleText
        entryFieldStyleName: passwordFieldFontStyleName
        entryFieldEchoMode: TextInput.Password
        width: parent.width - entryFieldFontPixelSize
    }

    IconButton {
        id: iconButton
        height: entryField.entryFieldFontPixelSize
        width: height
        anchors {
            left: entryField.right
            bottom: entryField.bottom
            bottomMargin: entryField.entryFieldFontPixelSize / 3
        }
        iconButtonSource: "qrc:/icons/svgs/icon-show-password.svg"

        onButtonPressed: {
            entryField.entryFieldEchoMode = TextInput.Normal
        }

        onButtonReleased: {
            entryField.entryFieldEchoMode = TextInput.Password
        }
    }
}
