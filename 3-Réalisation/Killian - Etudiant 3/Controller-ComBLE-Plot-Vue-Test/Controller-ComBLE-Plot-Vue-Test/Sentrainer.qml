
import QtQuick 2.15
import QtQuick.Controls 2.15

import entitePlot 1.0

Item {




    anchors.fill: parent
    property int nbPlotSelectionnes: 0

    ListView {
        id: listPlot
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: detectButton.top
        anchors.bottomMargin: 33
        model: controller.listePlotsSelected
        delegate: PlotVue {
            nomPlot: nom
            nvBatteriePlot: nvBatterie
            idPlot: id
            }
        }
}
