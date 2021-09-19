import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

RowLayout {
    id: root

    property CC_QmlField qmlField
    property bool readOnly: false

    anchors.verticalCenter: parent.verticalCenter
    anchors.leftMargin: 5
    anchors.rightMargin: 5
    
    Label {
        text: "0x"
    }

    CC_BasicSerValueTextField {
        id: rawValue
        text: qmlField ? qmlField.serStr : ""
        readOnly: root.readOnly

        onTextChanged: {
            qmlField.serStr = text;
            text = Qt.binding(function() { return qmlField.serStr; })
        }
    }

    Item {
        Layout.fillWidth: true
    }
}