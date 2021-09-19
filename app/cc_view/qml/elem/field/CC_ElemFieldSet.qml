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

    CC_BasicFieldFrame {
        anchors.fill: parent
        qmlField: root.qmlField
    }

    ColumnLayout {
        id: leftSide
        anchors.left: parent.left
        anchors.right: sep.left
        anchors.top: parent.top
        anchors.leftMargin: 5
        anchors.rightMargin: 5

        RowLayout {
            Layout.minimumHeight: 40

            CC_BasicFieldNameLabel {
                qmlField: root.qmlField
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

        Item {
            Layout.minimumHeight: 3
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

    CC_BasicFieldSerValue {
        anchors.left: sep.right
        anchors.right: parent.right
        readOnly: root.readOnly
        qmlField: root.qmlField
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