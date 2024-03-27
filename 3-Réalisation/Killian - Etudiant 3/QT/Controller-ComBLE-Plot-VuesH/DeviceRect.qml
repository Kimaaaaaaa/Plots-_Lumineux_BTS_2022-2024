import QtQuick 2.15
import QtQuick.Controls 2.15

Item{

    property string nomPlot
    property int nvBatterie

    width: 200
    height: 50

    Rectangle {
        anchors.fill: parent
        color: "lightblue"
        border.color: "blue"
        radius: 5
        Text {
            anchors.centerIn: parent
            text: nomPlot
        }
        Text {
            anchors.centerIn: parent
            text: nvBatterie
        }
    }
}
