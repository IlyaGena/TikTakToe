import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.11

Window {
    id: mainPage
    property int valueForWidth: width

    //    width: screen.width
    //    height: screen.height

    width: 400
    height: 680

    visible: true
    title: qsTr("TikTakToe")

    Rectangle {

        gradient: Gradient {
            GradientStop { position: 0.0; color: "#87cbff" }
            GradientStop { position: 0.33; color: "#c8ffa8" }
            GradientStop { position: 1.0; color: "#ffbdee" }
        }

        Rectangle {
            id: recLable

            Text {
                id: lableHello
                text: qsTr("Welcome to the game TikTakToe")
                font.pointSize: 15
                font.family: "Helvetica"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.bottom: place.top
        }


        GameTable{
            id: place
            width: Math.round(valueForWidth/1.5) - (Math.round(valueForWidth/1.5)%3)
            height: width

            anchors.centerIn: parent
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
