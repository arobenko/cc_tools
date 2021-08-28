import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/basic"

ToolBar {
    id: root
    height: 40
    background: CC_ToolbarBackground {}
    // anchors.left: parent.left
    // anchors.right: parent.right

    RowLayout {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        spacing: 6

        CC_BasicToolButton {
            id: addButton
            image.source: "qrc:/image/add.png"
            tooltip.text: qsTr("Add Message")
            shortcut.sequence: "Ctrl+M"
            enabled: CC_GuiState.pluginsApplied

            onClicked: {
                CC_GuiState.activateDialog(CC_GuiState.DialogType_AddNewSendMessage);
            }            
        }
    }
}
