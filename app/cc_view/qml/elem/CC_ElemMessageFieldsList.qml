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

        onLoaded: {
            elem.item.qmlMessage = root.qmlMessage
            elem.item.fieldIdx = index
            elem.item.readOnly = Qt.binding(function() { return root.readOnly; });
        }     
    }
}