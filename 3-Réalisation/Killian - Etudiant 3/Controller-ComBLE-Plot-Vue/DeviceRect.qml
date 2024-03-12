import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    width: 200
    height: 50
    color: "lightblue"
    border.color: "blue"
    radius: 5
    Text {
        anchors.centerIn: parent
        text: deviceName
    }
}
