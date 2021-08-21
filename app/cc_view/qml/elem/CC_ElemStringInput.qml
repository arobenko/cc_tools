import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

import "qrc:/qml/basic"

RowLayout {
    id: root

    property alias label: label
    property alias spacer: spacer
    property alias textField: textField
    property alias clearButton: clearButton
    property alias textFocusShortcut: textFocusShortcut

    Label {
        id: label
        text: qsTr("Input:")
    }

    Item {
        id: spacer
        Layout.fillWidth: true
    }

    TextField {
        id: textField
    }   

    CC_BasicToolButton {
        id: clearButton
        image.source: "qrc:/image/broom.png"
        tooltip.text: "Clear"
        shortcut.sequence: "Ctrl+L"
        enabled: root.enabled && (textField.text != "")
        onClicked: {
            textField.text = "";
            textField.forceActiveFocus();
        }
    }

    Shortcut {
        id: textFocusShortcut
        sequence: ""
        onActivated: textField.forceActiveFocus();
        enabled: textField.enabled && (sequence != "")
    }    
}