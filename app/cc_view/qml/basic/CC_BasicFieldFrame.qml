import QtQuick 2.12
import QtQuick.Controls 2.12
import CC 1.0

Rectangle {
    id: root

    property CC_QmlField qmlField
    property bool fieldValid: qmlField && qmlField.valid

    border.color: fieldValid ? "black" : "red"
    border.width: 1
    color: "transparent"
    radius: 5

    Rectangle {
        color: root.fieldValid ? "transparent" : "red"
        radius: root.radius
        opacity: 0.2
        anchors.fill: parent
    }
}