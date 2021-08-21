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
        anchors.bottom:parent.bottom

        model: CC_AvailableMessagesListModel {
            search: searchInput.textField.text
        }

        delegate: Text {
            text: listView.model.getNameOf(index);
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

