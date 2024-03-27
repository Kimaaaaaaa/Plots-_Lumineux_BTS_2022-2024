import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 450
    height: 900
    title: "Detection de Plots"

    ConfigurerPlots {
        id: configurerPlotsPage
        visible: true
    }

    Sentrainer{
        id: sentrainerPage
        visible: false
    }

   /* StackView{
        id: stackView
        anchors.fill: parent
    }*/

}
ddsds
