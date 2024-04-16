import QtQuick 2.15
import QtCharts 2.7
import QtQuick.Controls 2.15
import QtCharts 2.3

Page {
    visible: true
    width: 450
    height: 900
    title: "Graphique de moyenne"

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"


        Text {
            id: titre
            text: "Graphique de moyenne du
Joueur "
            font.bold: true
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
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
