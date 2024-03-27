
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
