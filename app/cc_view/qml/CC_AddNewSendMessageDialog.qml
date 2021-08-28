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
    height: Screen.desktopAvailableHeight * 0.4
    width: Screen.desktopAvailableWidth * 0.4

    CC_MessageCreator {
        id: creator
    }

    CC_ElemSearchMessagesStringInput {
        id: searchInput
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
    }

    ScrollView {
        anchors.top: searchInput.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom:parent.bottom  
                
        CC_ElemAvailableMessageTypesList {
            id: listView
            searchInput: searchInput.textField.text
            anchors.fill: parent
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

