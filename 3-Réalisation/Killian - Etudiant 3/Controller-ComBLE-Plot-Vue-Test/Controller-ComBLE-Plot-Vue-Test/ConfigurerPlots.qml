import QtQuick 2.15
import QtQuick.Controls 2.15
import entitePlot 1.0

Item {
    anchors.fill: parent

    signal selectedPlotsChanged(var selectedPlots)

    property int nbPlotSelectionnes: 0

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

    // Définir un modèle de bouton pour débuter la partie
    Button {
        id: test

        text: "Débuter partie"
        anchors.bottomMargin: 44

        width: 159
        height: 33
        anchors {
            bottom: parent.bottom  // Ancre le bas du bouton au bas de la fenêtre
            horizontalCenter: parent.horizontalCenter  // Centre horizontalement le bouton dans la fenêtre
        }

        enabled: nbPlotSelectionnes >= 2

        background: Rectangle {
            anchors.fill: parent
            color: "#FFB22A"
            border.color:  "black"
            border.width: 1
        }

        onClicked: {
                  console.log("cliq");
                  sentrainerPage.visible = true;
                  configurerPlotsPage.visible = false;
              }
    }

    ListView {
        id: listPlot
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: detectButton.top
        anchors.bottomMargin: 33
        model: controller.listePlots
        delegate: PlotVue {
            nomPlot: nom
            nvBatteriePlot: nvBatterie
            idPlot: id
            selectedPlot: selected

            onSelectedPlotChanged: {
                selected = selectedPlot;
                if(selectedPlot){
                    nbPlotSelectionnes++;
                }else{
                    nbPlotSelectionnes--;
                }
                console.log(nbPlotSelectionnes)
            }
        }
    }
}
