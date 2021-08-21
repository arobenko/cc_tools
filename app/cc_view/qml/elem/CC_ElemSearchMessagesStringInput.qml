import "qrc:/qml/elem"

CC_ElemSearchStringInput {
    id: root
    textField.placeholderText: qsTr("Message name") + " (" + textFocusShortcut.nativeText + ')'
    textFocusShortcut.sequence: "Alt+S"
}