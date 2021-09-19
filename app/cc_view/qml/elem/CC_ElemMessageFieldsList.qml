import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

ListView {
    id: root

    property CC_QmlMessage qmlMessage
    property bool readOnly: false

    spacing: 3

    model: CC_MessageFieldsListModel {
        msg: qmlMessage.msg
    }

    delegate: Loader {
        id: elem
        source: dataFieldQml
        active: source != ""
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 5
        anchors.rightMargin: 5

        CC_QmlField {
            id: qmlField
            msg: qmlMessage.msg
            idx: index
        }

        // Rectangle {
        //     border.color: "black"
        //     border.width: 1
        //     color: "transparent"
        //     anchors.fill: parent
        //     radius: 5
        // }

        onLoaded: {
            elem.item.qmlField = qmlField
            elem.item.readOnly = Qt.binding(function() { return root.readOnly; });
        }    
    }
}