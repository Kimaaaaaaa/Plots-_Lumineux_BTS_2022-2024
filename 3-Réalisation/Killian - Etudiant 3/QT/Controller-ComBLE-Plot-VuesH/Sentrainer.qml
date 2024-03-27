
import QtQuick 2.15
import QtQuick.Controls 2.15

import entitePlot 1.0

Item {

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"
    }


    anchors.fill: parent
    property int nbPlotSelectionnes: 0



    property var selectedPlots: []

    GridView {
        id: listePlotsSelected

        Connections {
            target: controller
            function onPlotAllumeChanged(index, color, id) {
                listePlotsSelected.updatePlotColor(index, color);
            }
        }

        function updatePlotColor(index, color) {
            // Vérifiez si l'index est valide
            if (index >= 0 && index < selectedPlots.length) {
                // Mettez à jour la couleur du plot à l'index spécifié
                console.log("Couleur : " + color);
                console.log("Index du plot : " + index);
                selectedPlots[index].color = color;
            }
        }




        anchors.fill: parent
        cellHeight: cellWidth
        cellWidth: parent.width/2
        interactive: false
        // orientation: ListView.Horizontal
        anchors.topMargin: 100
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.top
        anchors.bottomMargin: 33
        model: selectedPlots
        delegate: PlotSelectedVue{
            nomPlot: nom
            nvBatteriePlot: nvBatterie
            idPlot: id
            isSelect: false
            color: getColorById(idPlot) // Utilisez la fonction pour obtenir la couleur en fonction de l'ID
        }
    }

    function getColorById(id) {
        switch(id) {
            case 0: return "red"; // Utilisez les ID pour déterminer la couleur
            case 1: return "blue";
            case 2: return "green";
            case 3: return "yellow";
            case 4: return "white";
            default: return "#c4c7c4";
        }
    }


    Button {
        id: test

        text: "Lancer la partie"
        anchors.bottomMargin: 44

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
                  console.log("allumer plot aleatoire");
                  controller.allumerPlotAleatoire();
              }
    }

}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
