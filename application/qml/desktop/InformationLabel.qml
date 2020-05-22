import QtQuick 2.0
import QtQuick.Controls 2.5

Label {
    property bool errorHighlighted

    color: errorHighlighted ? "red" : "#00B4AB"

    font.styleName: "Roboto"
    wrapMode: Text.WordWrap
}

