import QtQuick 2.15
import QtQuick.Window 2.15

import Backend 1.1

Rectangle {
    BackendTable{
        id: backend
    }

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
            }
        }
    }

    TableView {
        id: table
        model: backend
        delegate: delegateMode

        anchors.fill: parent
    }

    onWidthChanged: {
        table.forceLayout();
    }
}
