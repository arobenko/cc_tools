import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    property int edgeMargin: 5
    property bool dragAllowed: true
    property int dragWidth: 20
    property int dragMinX: 0
    property int dragMaxX: parent.width

    width: 1
    color: "black"
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    anchors.topMargin: edgeMargin
    anchors.bottomMargin: edgeMargin

    MouseArea {
        cursorShape: root.dragAllowed ? Qt.SplitHCursor : Qt.ArrowCursor
        anchors.fill: parent
        anchors.leftMargin: -(dragWidth / 2)
        anchors.rightMargin: -(dragWidth / 2)

        drag.target: root.dragAllowed ? root : undefined
        drag.axis: Drag.XAxis
        drag.minimumX: root.dragMinX
        drag.maximumX: root.dragMaxX      
    }
}