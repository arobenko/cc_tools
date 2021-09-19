import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

import "qrc:/qml/basic"

Item {
    id: root

    property CC_QmlField qmlField
    property bool readOnly: false

    height: leftSide.height

    ColumnLayout {
        id: leftSide
        anchors.left: parent.left
        anchors.right: sep.left
        anchors.top: parent.top

        RowLayout {
            Layout.minimumHeight: 40

            Label {
                id: nameLabel
                text: (0 < qmlSetField.name.length) ? qmlSetField.name + ':' : ""
            }

            Item {
                Layout.fillWidth: true
            }
        }

        RowLayout {
            Item {
                Layout.minimumWidth: 10
            }

            ListView {
                id: bits
                Layout.minimumHeight: contentHeight
                model: setBitsModel
                delegate: RowLayout {
                    spacing: 3
                    CheckBox {
                        checkState: dataState ? Qt.Checked : Qt.Unchecked

                        onCheckStateChanged: {
                            if (!root.readOnly) {
                                dataState = (checkState == Qt.Checked);
                            }
                            checkState = Qt.binding(function() { return dataState ? Qt.Checked : Qt.Unchecked; })
                        }
                    }

                    Label {
                        text: dataName
                    }

                    Item {
                        Layout.fillWidth: true
                    }
                }
            }
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
        height: 40
        
        Label {
            text: "0x"
        }

        CC_BasicSerValueTextField {
            id: rawValue
            text: qmlSetField.serStr
            readOnly: root.readOnly

            onTextChanged: {
                qmlSetField.serStr = text;
                text = Qt.binding(function() { return qmlSetField.serStr; })
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }

    CC_QmlSetField {
        id: qmlSetField
        field: root.qmlField.field
    }

    CC_SetBitsModel {
        id: setBitsModel
        setField: qmlSetField.setField
    }
}