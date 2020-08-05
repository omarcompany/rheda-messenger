import QtQuick 2.13
import elevons.team 1.0
import QtQuick.Controls 2.0

Label  {
    text: qsTr("Your ID: %1").arg(Messenger.userId)
}
