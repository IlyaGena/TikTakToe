import QtQuick 2.15
import QtQuick.Window 2.15

Rectangle {

    Component {
        id: delegateMode

        Item {
            id: item

            required property string display
            property string size: table.width/backend.columnCount()

            implicitWidth: size
            implicitHeight: size

            Rectangle {
                width: parent.width
                height: parent.height
                color: "#e1fae9"
                border.color: "#000000"

                Image {
                    height: parent.height
                    width: parent.width

                    source: getVal()

                    function getVal()
                    {
                        if (display == "Null")
                            return ""
                        else if (display == "X")
                            return "qrc:/img/cross.png"
                        else if (display == "O")
                            return "qrc:/img/zero.png"
                    }
                }
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    backend.setData(backend.index(row,column))
                }
            }
        }
    }

    TableView {
        id: table
        delegate: delegateMode

        anchors.fill: parent
    }

    onWidthChanged: {
        table.forceLayout();
    }
    onVisibleChanged: {
        if (visible)
            table.model = backend
    }
}
