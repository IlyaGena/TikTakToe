import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11

import Backend 1.1

Window {
    id: mainPage
    property int valueForWidth: width

    //    width: screen.width
    //    height: screen.height

    width: 400
    height: 680

    visible: true
    title: qsTr("TikTakToe")

    BackendTable{
        id: backend
    }

    Connections {
        target: backend
        function onSig_StartGame(){
            place.visible = true
            rec_O.visible = true
            rec_X.visible = true
            ask_X_O.visible = false
        }
        function onSig_EndGame(){
            place.visible = false
            rec_O.visible = false
            rec_X.visible = false
            recEndGame.visible = true
            rec_yes.visible = true
            rec_no.visible = true
        }
    }

    FontLoader {
        id: fontLoader
        source: "qrc:/fonts/cabana.ttf"
    }

    Rectangle {
        Image {
            id: fonGame
            source: "qrc:/img/fonGame.png"
            anchors.fill: parent
        }

        Rectangle {
            id: recLable

            Text {
                id: lableHello
                text: qsTr("Welcome to the game TikTakToe")
                font.pointSize: 40
                font.family: fontLoader.name

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottom: place.top
        }


        GameTable{
            id: place
            visible: false
            width: Math.round(valueForWidth/1.5) - (Math.round(valueForWidth/1.5)%3)
            height: width

            anchors.centerIn: parent
        }

        AskPage {
            id: ask_X_O
            anchors.fill: parent
        }

        Rectangle {
            id: rec_X
            color: "#00000000"
            width: lable_X.width
            height: lable_X.height
            visible: false

            Text {
                id: lable_X
                text: qsTr("X")
                font.family: fontLoader.name
                font.pointSize: mainPage.width/5
                font.bold: true
            }
            anchors.left: parent.left
            anchors.leftMargin: lable_X.font.pointSize
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
        }

        Rectangle {
            id: rec_O
            color: "#00000000"
            width: lable_O.width
            height: lable_O.height
            visible: false

            Text {
                id: lable_O
                text: qsTr("0")
                font.family: fontLoader.name
                font.pointSize: mainPage.width/5
                font.bold: true
            }
            anchors.right: parent.right
            anchors.rightMargin: lable_O.font.pointSize
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
        }

        Rectangle {
            id: recEndGame
            width: textEndGame.width
            height: textEndGame.height
            color: "#00000000"
            visible: false

            Text {
                id: textEndGame
                font.pointSize: mainPage.width/10
                font.family: fontLoader.name
                text: qsTr("Игра окончена. \nХотите начать новую?")

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            anchors.centerIn: parent
        }

        Rectangle {
            id: rec_yes
            color: "#00000000"
            width: lable_yes.width
            height: lable_yes.height
            visible: false

            Text {
                id: lable_yes
                text: qsTr("Да")
                font.family: fontLoader.name
                font.pointSize: mainPage.width/10
            }
            MouseArea {
                onClicked: {
                    backend.newGame()

                    place.visible = true
                    rec_O.visible = true
                    rec_X.visible = true
                    recEndGame.visible = false
                    rec_yes.visible = false
                    rec_no.visible = false
                }

                anchors.fill: parent
            }

            anchors.left: parent.left
            anchors.leftMargin: lable_yes.font.pointSize*2
            anchors.bottom: parent.bottom
            anchors.bottomMargin: lable_yes.font.pointSize*2
        }

        Rectangle {
            id: rec_no
            color: "#00000000"
            width: lable_no.width
            height: lable_no.height
            visible: false

            Text {
                id: lable_no
                text: qsTr("Нет")
                font.family: fontLoader.name
                font.pointSize: mainPage.width/10
            }

            MouseArea {
                onClicked: {
                    recEndGame.visible = false
                    rec_no.visible = false
                    rec_yes.visible = false
                    ask_X_O.visible = true
                }

                anchors.fill: parent
            }

            anchors.right: parent.right
            anchors.rightMargin: lable_no.font.pointSize*2
            anchors.bottom: parent.bottom
            anchors.bottomMargin: lable_no.font.pointSize*2
        }

        onWidthChanged: {
            if (width > height)
                valueForWidth = height
            else
                valueForWidth = width
        }

        onHeightChanged: {
            if (width > height)
                valueForWidth = height
            else
                valueForWidth = width
        }

        anchors.fill: parent
    }

}
