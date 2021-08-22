import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import CC 1.0

import "qrc:/qml"
import "qrc:/qml/elem"

Dialog {
    id: root
    title: "Create New Message to Send"
    standardButtons: StandardButton.Cancel | StandardButton.Ok
    height: Screen.desktopAvailableHeight * 0.8
    width: Screen.desktopAvailableWidth * 0.4

    CC_ElemSearchMessagesStringInput {
        id: searchInput
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    ListView {
        id: listView
        anchors.top: searchInput.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom:parent.bottom

        model: CC_AvailableMessagesListModel {
            search: searchInput.textField.text
        }

        delegate: Rectangle {
            id: elem
            border.color: ListView.isCurrentItem ? "blue" : color
            height: 30
            radius: 5
            anchors.left: parent.left
            anchors.right: parent.right

            Text {
                text: listView.model.getNameOf(index);
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
                    console.log("!!!Clicked")
                    // var indexChanged = listView.currentIndex != index;
                    // if (!indexChanged) {
                    //     listView.currentIndex = -1;    
                    //     return;
                    // }

                    listView.currentIndex = index;
                    //root.pluginIid = listView.model.getIidOf(index);
                }
            }            
        }
    }

    onAccepted: {
        console.log("!!! Accepted");
        CC_GuiState.closeCurrentDialog();
    }

    onRejected: {
        console.log("!!! Rejected");
        CC_GuiState.closeCurrentDialog();
    }

    Component.onCompleted: {
        visible = true;
    }
}

