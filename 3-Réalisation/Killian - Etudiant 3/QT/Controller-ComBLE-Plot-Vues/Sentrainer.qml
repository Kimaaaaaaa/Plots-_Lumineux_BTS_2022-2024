
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


    // Define a property to hold the selected plots
    property var selectedPlots: []

    ListView {
        id: listePlotsSelected
        anchors.fill: parent
        anchors.topMargin: 176
        anchors.leftMargin: 0
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: detectButton.top
        anchors.bottomMargin: 33
        model: selectedPlots
        delegate: PlotVue{
            nomPlot: nom
            nvBatteriePlot: nvBatterie
            idPlot: id
        }
    }
}




