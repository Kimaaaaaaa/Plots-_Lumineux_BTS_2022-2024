import QtQuick 2.15
import QtQuick.Controls 2.15

import entitePlot 1.0

ApplicationWindow {
    visible: true
    width: 450
    height: 900
    title: "Detection de Plots"

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"
    }

    Connections {
        target: controller
        function onStatutScanEnCours() {
            detectButton.enabled = false
            detectButton.text = "Scan en cours ...."
        }
    }
    Connections {
        target: controller
        function onStatutScanTermine() {
            detectButton.enabled = true
            detectButton.text = "Détecter les plots"
        }
    }

    // Définir un modèle de bouton pour détecter les plots
    Button {
        id: detectButton
        y: 856
        text: "Détecter les plots"
        anchors.bottomMargin: 11

        width: 159
        height: 33
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
        id: listPlot
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: detectButton.top
        model: controller.listePlots
        delegate: PlotVue {
            nomPlot: nom
            nvBatteriePlot: nvBatterie
            selectedPlot : selected
            onSelectedPlotChanged: {
                selected = selectedPlot;
                controller.m_selectedPlotsCount++
                console.log(controller.m_selectedPlotsCount)
            }
        }
    }

}
