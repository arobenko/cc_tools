import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

Item {
    id: root

    property CC_QmlMessage qmlMessage
    property bool readOnly: false
    property int fieldIdx: 0

    height: 40

    RowLayout {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: sep.left

        Label {
            id: nameLabel
            text: "ENUM:"
        }

        ComboBox {
        }

        Item {
            Layout.fillWidth: true
        }
    }

    Rectangle {
        id: sep
        width: 1
        color: "black"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 3
        anchors.bottomMargin: 3
    }

    RowLayout {
        anchors.left: sep.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        
        Label {
            text: "0x"
        }

        TextField {
            
        }

        Item {
            Layout.fillWidth: true
        }
    }

}