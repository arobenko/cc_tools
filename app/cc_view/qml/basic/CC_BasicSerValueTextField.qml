import QtQuick 2.12
import QtQuick.Controls 2.12

TextField {
    id: root
    inputMask: "hhhhhhhhhhhhhhhh"

    onTextChanged: {
        if (text.length < cursorPosition) {
            cursorPosition = text.length
        }
    }
}