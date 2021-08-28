import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

ColumnLayout {
    id: root
    spacing: 5

    property CC_QmlMessage qmlMessage

    Label {
        id: name
        text: qmlMessage.infoString
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pointSize: 14

        Layout.fillWidth: true
    }

    Rectangle {
        height: 1
        color: "black"
        Layout.fillWidth: true
        Layout.leftMargin: 5
        Layout.rightMargin: 5
    }

    Item {
        Layout.fillHeight: true
    }
}