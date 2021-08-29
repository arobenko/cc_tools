import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

Label {
    id: root
    text: "INT"

    property CC_QmlMessage qmlMessage
    property bool readOnly: false
    property int fieldIdx: 0
}