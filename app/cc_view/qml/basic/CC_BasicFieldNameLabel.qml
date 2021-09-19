import QtQuick 2.12
import QtQuick.Controls 2.12
import CC 1.0

Label {
    id: root
    property CC_QmlField qmlField
    text: (qmlField && (0 < qmlField.name.length)) ? qmlField.name + ':' : ""
}