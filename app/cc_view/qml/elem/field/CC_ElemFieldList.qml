import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import CC 1.0

Label {
    id: root
    text: "LIST"

    property CC_QmlField qmlField
    property bool readOnly: false
}