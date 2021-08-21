import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/basic"

ToolBar {
    id: root
    height: 40
    background: CC_ToolbarBackground {}
    anchors.left: parent.left
    anchors.right: parent.right

    RowLayout {
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        spacing: 6

        CC_BasicToolButton {
            image.source: "qrc:/image/plugin_select.png"
            tooltip.text: qsTr("Select plugins")
            shortcut.sequence: "Ctrl+P"

            onClicked: {
                CC_GuiState.activateDialog(CC_GuiState.DialogType_PluginsSelection);
            }            
        }

        Repeater {
            model: CC_GuiState.extraToolbarElements
            Loader {
                source: modelData
                active: source !== ""
            }
        }
    }
}
