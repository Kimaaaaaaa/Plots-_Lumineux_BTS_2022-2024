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

        function updatePlotColor(index, newColor) {

            var item = listePlotsSelected.itemAtIndex(index);
            if (item) {
                // Mettre à jour la couleur de l'élément
                item.color = newColor;
            } else {
                console.error("Impossible de trouver l'élément à l'index", index);
            }
        }

        Connections {
            target: controller
            onPlotAllumeChanged: {
                var color = colorVariant.toString();
                var index = controller.getIndexByIdSelectedPlot(idPlotAllume);

                console.log("Plot allumé avec la couleur :", color);
                console.log("Plot allumé à l'index :", index);
                listePlotsSelected.updatePlotColor(index, color); // Passer la couleur comme paramètre
            }
        }







        anchors.fill: parent
        cellHeight: cellWidth
        cellWidth: parent.width/2
        interactive: true
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
            color: "#D3D3D3"
            indexListe: index

            MouseArea {
                    anchors.fill: parent // Capturer les clics sur toute la zone de l'élément PlotSelectedVue

                    onClicked: {

                        console.log("Plot sélectionné:", nomPlot);
                        // Exemple de modification de la couleur lors du clic
                        color = "#D3D3D3"; // Changer la couleur du plot au rouge lors du clic
                        controller.plotTouche(idPlot);
                        controller.eteindreToutLesPlots();

                    }
                }
        }
    }





    Button {
        id: btnLancerLaPartie

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
                  console.log("Lancement de la partie");
                  //controller.allumerPlotAleatoire();



                  controller.lancerPartieJ1(5, 200, "random");
              }
        Connections {
                    target: controller
                    onPartieLaunchedChanged: {
                    btnLancerLaPartie.enabled = !isLaunched
            }
        }
    }

}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
