import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property int idPlot
    property string nomPlot
    property int nvBatteriePlot
    property bool selectedPlot
    property bool isSelect : true



    width: parent.width // Définir la largeur de l'élément sur la largeur de la liste
    height: 60 // Hauteur de l'élément
    Rectangle {
        width: parent.width
        height: parent.height
        color: selectedPlot ? "#FFB22A" : "#00B000" // Couleur orange
        border.color: "black" // Couleur de la bordure
        Text {
            text: "Nom : " + nomPlot // Afficher le nom du périphérique
            anchors.centerIn: parent
            font.bold: true
            topPadding: 30
        }
        Text {
            text: "Niveau de batterie : " + nvBatteriePlot + "%" // Afficher le nom du périphérique
            anchors.centerIn: parent
            font.bold: true
        }
        Text {
            y: 0
            text: "ID du plot : " + idPlot // Utilisation de la propriété idPlot au lieu de id
            anchors.horizontalCenterOffset: -148
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
                bottomMargin: 47
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(isSelect)
                    selectedPlot = !selectedPlot;
            }
        }
    }
}
