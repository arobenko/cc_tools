import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import CC 1.0

import "qrc:/qml"
import "qrc:/qml/basic"
import "qrc:/qml/elem"

Dialog {
    id: root
    title: "Create New Message to Send"
    standardButtons: StandardButton.Cancel | StandardButton.Ok
    height: Screen.desktopAvailableHeight * 0.8
    width: Screen.desktopAvailableWidth * 0.8

    CC_MessageCreator {
        id: creator
    }

    ColumnLayout {
        id: leftSide
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: splitter.left

        CC_ElemSearchMessagesStringInput {
            id: searchInput
            spacer.visible: false
            backSpacer.visible: true
        }

        ScrollView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            contentHeight: availableHeight
                    
            CC_ElemAvailableMessageTypesList {
                id: listView
                searchInput: searchInput.textField.text
                anchors.fill: parent
            }
        }
    }

    Item {
        id: rightSide
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: splitter.right
        anchors.right: parent.right
    }

    CC_BasicHorSplitter {
        id: splitter
        x: parent.width / 2
        dragMinX: leftSide.implicitWidth
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

