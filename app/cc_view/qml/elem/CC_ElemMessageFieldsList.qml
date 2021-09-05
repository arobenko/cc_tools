import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

ListView {
    id: root

    property CC_QmlMessage qmlMessage
    property bool readOnly: false

    model: CC_MessageFieldsListModel {
        msg: qmlMessage.msg
    }

    delegate: Loader {
        id: elem
        source: fieldQml
        active: source != ""
        anchors.left: parent.left
        anchors.right: parent.right

        CC_QmlField {
            id: qmlField
            msg: qmlMessage.msg
            idx: index
        }

        onLoaded: {
            elem.item.qmlMessage = root.qmlMessage
            elem.item.qmlField = qmlField
            elem.item.readOnly = Qt.binding(function() { return root.readOnly; });
        }     
    }
}