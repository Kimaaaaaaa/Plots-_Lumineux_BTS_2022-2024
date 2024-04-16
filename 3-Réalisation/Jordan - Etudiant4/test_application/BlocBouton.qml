import QtQuick 2.0

Item {
    property alias valeur : text.text
    width: 115
    height: 35

    Rectangle {
        anchors.fill : parent
        width: 115; height: 35
        color: "#FFB22A"

    MouseArea {
        anchors.fill : parent
        width: 200; height: 35

    }
}
}
