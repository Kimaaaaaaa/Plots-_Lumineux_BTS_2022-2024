import QtQuick 2.15
import QtQuick.Controls 2.15

import entitePlot 1.0

ApplicationWindow {
    visible: true
    width: 450
    height: 900
    title: "Detection de Plots"



    // Définir un modèle de bouton pour détecter les plots
    Button {
        id: detectButton
        text: "Détecter les plots"
        width: 275
        height :100
        anchors {
            bottom: parent.bottom  // Ancre le bas du bouton au bas de la fenêtre
            horizontalCenter: parent.horizontalCenter  // Centre horizontalement le bouton dans la fenêtre
        }

        background: Rectangle {
            anchors.fill: parent
            color: "#FFB22A"
            border.color:  "black"
            border.width: 1
        }


        onClicked: {
            console.log("startScanning");
            controller.startScanning()

        }
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.bottomMargin: 46
        model: controller.listePlots
        delegate: Item {
            width: listView.width // Définir la largeur de l'élément sur la largeur de la liste
            height: 60 // Hauteur de l'élément
            Rectangle {
                width: parent.width
                height: parent.height
                color: "#BBFAFC" // Couleur orange
                border.color: "black" // Couleur de la bordure
                Text {
                    text: m_nom // Afficher le nom du périphérique
                    anchors.centerIn: parent
                    font.bold: true
                }
                Text {
                    text: nvBatterie // Afficher le nom du périphérique
                    anchors.centerIn: parent
                    font.bold: true
                }
            }
        }
    }



}
