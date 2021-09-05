import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/elem"

ColumnLayout {
    id: root

    property CC_QmlMessage qmlMessage
    property bool readOnly: false

    spacing: 5

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

    CC_ElemMessageFieldsList {
        qmlMessage: root.qmlMessage
        readOnly: root.readOnly
        Layout.fillHeight: true
        Layout.fillWidth: true
    }

    // Item {
    //     Layout.fillHeight: true
    // }
}