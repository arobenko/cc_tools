import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/basic"

Item {
    id: root

    property CC_QmlField qmlField
    property bool readOnly: false

    height: 40

    RowLayout {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: sep.left

        Label {
            id: nameLabel
            text: (0 < qmlEnumField.name.length) ? qmlEnumField.name + ':' : ""
        }

        ComboBox {
            id: comboBox
            model: enumModel
            textRole: "dataName"
            currentIndex: enumModel.currentIndex

            onCurrentIndexChanged: {
                if (!root.readOnly) {
                    enumModel.currentIndex = currentIndex;
                }
                currentIndex = Qt.binding(function() { return enumModel.currentIndex; })
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }

    Rectangle {
        id: sep
        width: 1
        color: "black"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 3
        anchors.bottomMargin: 3
    }

    RowLayout {
        anchors.left: sep.right
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        
        Label {
            text: "0x"
        }

        CC_BasicSerValueTextField {
            id: rawValue
            text: qmlEnumField.serStr
            readOnly: root.readOnly

            onTextChanged: {
                qmlEnumField.serStr = text;
                text = Qt.binding(function() { return qmlEnumField.serStr; })
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }

    CC_QmlEnumField {
        id: qmlEnumField
        field: root.qmlField.field
    }

    CC_EnumValuesModel {
        id: enumModel
        enumField: qmlEnumField.enumField
    }
}