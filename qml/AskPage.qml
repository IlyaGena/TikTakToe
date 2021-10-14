import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {

    property int count_cell: 3
    property string elem: "X"

    Image {
        id: fon
        source: "qrc:/qml/fon.png"
        anchors.fill: parent
    }

    Rectangle {
        id: ask_elem

        width: parent.width/2
        height: parent.height/2
        color: "#00000000"

        Text {
            id: select_elem

            font.family: fontLoader.name
            font.pointSize: 30
            text: qsTr("Чем будете ходить?")

            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: ask_elem.horizontalCenter
        }

        Rectangle {
            id: cross
            color: "#00000000"
            width: text_X.width
            height: text_X.height

            Text {
                id: text_X
                font.family: fontLoader.name
                font.pointSize: 30
                text: qsTr("Крестики?")

                anchors.horizontalCenter: cross.horizontalCenter
                anchors.verticalCenter: cross.verticalCenter
            }

            MouseArea {
                onClicked: {
                    elem = "X"
                    text_X.text = elem
                    text_X.font.pointSize = 50

                    if (text_O.text == "0")
                    {
                        text_O.font.pointSize = 30
                        text_O.text = qsTr("Нолики?")
                    }
                }
                anchors.fill: parent
            }

            anchors.top: select_elem.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: ask_elem.horizontalCenter
        }
        Rectangle {
            id:zero
            color: "#00000000"

            width: text_O.width
            height: text_O.height

            Text {
                id: text_O
                font.family: fontLoader.name
                font.pointSize: 30
                text: qsTr("Нолики?")

                anchors.horizontalCenter: zero.horizontalCenter
                anchors.verticalCenter: zero.verticalCenter
            }

            MouseArea {
                onClicked: {
                    elem = "0"
                    text_O.text = elem
                    text_O.font.pointSize = 50

                    if (text_X.text == "X")
                    {
                        text_X.font.pointSize = 30
                        text_X.text = qsTr("Крестики?")
                    }
                }

                anchors.fill: parent
            }

            anchors.top: cross.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: ask_elem.horizontalCenter
        }

        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.right: parent.right
    }

    Rectangle {
        id: ask_count
        color: "#00000000"

        width: parent.width/2
        height: parent.height/3

        Text {
            id: text_change_count

            font.family: fontLoader.name
            font.pointSize: 20
            text: qsTr("Какой размер \nполя Вы предпочитаете?")

            anchors.top: parent.top
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: ask_count.horizontalCenter
        }

        Text {
            id: text_count

            font.family: fontLoader.name
            font.pointSize: 40
            font.bold: true
            text: count_cell

            anchors.bottom: btn_start.top
            anchors.bottomMargin: 10
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: ask_count.horizontalCenter
        }

        Rectangle {
            id: increment
            color: "#00000000"

            width: text_plus.width
            height: text_plus.height

            Text {
                id: text_plus

                font.family: fontLoader.name
                font.pointSize: 50
                font.bold: true
                text: qsTr("+")

                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea {
                anchors.fill: increment
                onClicked: {
                    count_cell++
                    text_count.text = count_cell
                }
            }

            anchors.top: text_change_count.bottom
            anchors.left: ask_count.left
            anchors.leftMargin: 30
        }

        Rectangle {
            id: decrement
            color: "#00000000"

            width: text_minus.width
            height: text_minus.height

            Text {
                id: text_minus

                font.family: fontLoader.name
                font.pointSize: 50
                font.bold: true
                text: qsTr("-")

                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea {
                anchors.fill: decrement
                onClicked: {
                    count_cell--
                    text_count.text = count_cell
                }
            }

            anchors.top: text_change_count.bottom
            anchors.right: ask_count.right
            anchors.rightMargin: 30
        }

        Button {
            id: btn_start
            width: name_btn_start.width + 20
            height: name_btn_start.height

            contentItem: Rectangle {
                color: "#00000000"
                Label {
                    id: name_btn_start

                    text: qsTr("Start")
                    font.family: fontLoader.name
                    font.pointSize: 30
                    font.bold: true

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            background: Rectangle {
                id: rec_btn_start

                color: "#00000000"
                border.color: "#000000"
                radius: 10
            }

            onClicked: {
                backend.startGame(count_cell, elem)
            }

            anchors.bottom: ask_count.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: ask_count.horizontalCenter
        }

        anchors.left: ask_X_O.left
        anchors.bottom: ask_X_O.bottom
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
