import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root

    property bool fieldValid: true

    border.color: "black"
    border.width: 1
    color: "transparent"
    radius: 5

    Rectangle {
        color: root.fieldValid ? "transparent" : "red"
        radius: root.radius
        opacity: 0.2
    }
}