import QtQuick 2.11

Rectangle {
    id: root
    height: 700
    ListModel {
        id: messageList
        dynamicRoles: true
        Component.onCompleted: {
            for (var i = 0; i <= 100; i++) {
                append({})
            }
        }
    }

    ListView {
        verticalLayoutDirection: ListView.BottomToTop
        anchors.fill: parent
        spacing: 2
        model: messageList
        clip: true
        delegate: MessageDelegate {
            userName: "Dukalis Andruha"
            text: "Сегодня мы познакомимся с Вами еще с одним лингвистическим явлением, которое называется «панграмма». Это греческий термин, который означает «παν» - «все» и «γραμμα» - «буква» и обозначает фразу или предложение, которое содержит все или почти все буквы алфавита того или иного языка. В некоторых языках из-за специфичности алфавита очень сложно составить панграммы с повторением буквы в предложении только один раз, поэтому допустимы отклонения от этого правила: некоторые буквы могут повторяться, используются сокращения, в соответствии с древнеримской традицией буквы J и U заменяются на I и V."
            timestamp: "22-05-2020 23:12:56"
        }
    }
}
