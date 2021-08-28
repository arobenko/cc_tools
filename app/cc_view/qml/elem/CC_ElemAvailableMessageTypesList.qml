import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

ListView {
    id: root

    property string searchInput: ""

    signal sigMessageSelected(int id, int idx)

    currentIndex: -1

    model: CC_AvailableMessagesListModel {
        search: root.searchInput
    }

    delegate: Rectangle {
        id: elem
        border.color: ListView.isCurrentItem ? "blue" : color
        height: 30
        radius: 5
        anchors.left: parent.left
        anchors.right: parent.right

        Text {
            text: root.model.getNameOf(index);
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            enabled: true

            onClicked: {
                root.currentIndex = index;
                root.sigMessageSelected(root.model.getIdOf(index), root.model.getIdxOf(index));
            }
        }     
    }
}