import QtQuick 2.15
import QtQuick.Controls 2.15
import QtCharts 2.7

Page {
    visible: true
    width: 450
    height: 900
    title: "Afficher Statistiques"

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"

        Text {
            id: titleText
            text: "Statistiques détaillées"
            font.bold: true
            font.pixelSize: 24
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter

        }









        Button {
            text: "Retour"
            onClicked: {
                stackView.pop()
            }
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            background: Rectangle {
                color: "#FFB22A"
                radius: 10
            }
            font.pixelSize: 16
        }
    }
}
