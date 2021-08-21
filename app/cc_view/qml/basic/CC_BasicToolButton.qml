import QtQuick 2.12
import QtQuick.Controls 2.12

import "qrc:/qml/basic"

ToolButton {
    id: root
    icon.source: image.source
    display: ToolButton.IconOnly
    hoverEnabled: tooltip.text !== ""
    opacity: enabled ? 1.0 : 0.4

    property alias image: image
    property alias tooltip: tooltip
    property alias shortcut: shortcut

    Image {
        id: image
        anchors.fill: parent
        anchors.margins: 2
    }

    CC_BasicTooltip {
        id: tooltip
        show: root.hovered
        shortcutText: shortcut.enabled ? shortcut.nativeText : ""
    }

    Shortcut {
        id: shortcut
        sequence: ""
        enabled: root.enabled && (sequence != "")
        onActivated: {
            root.onClicked();
        }
    }
}

