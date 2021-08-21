import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/basic"

    ToolBar {
        id: toolbar
        height: 40
        background: CC_ToolbarBackground {}

        RowLayout {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            spacing: 6

            CC_BasicToolButton {
                id: openToolbutton
                image.source: "qrc:/image/folder.png"
                tooltip.text: qsTr("Open")
                shortcut.sequence: "Ctrl+O"

                onClicked: {
                    CC_GuiState.activateDialogPrepend(CC_GuiState.DialogType_PluginsConfigLoad);
                }            
            }

            CC_BasicToolButton {
                id: saveToolbutton
                image.source: "qrc:/image/save_as.png"
                tooltip.text: qsTr("Save")
                shortcut.sequence: "Ctrl+S"

                onClicked: {
                    CC_GuiState.activateDialogPrepend(CC_GuiState.DialogType_PluginsConfigSave);
                }            
            }
        }
    }
