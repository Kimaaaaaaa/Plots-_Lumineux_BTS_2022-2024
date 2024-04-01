import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property int idPlot
    property string nomPlot
    property string indexListe
    property int nvBatteriePlot
    property bool selectedPlot
    property bool isSelect : true
    property string color // Ajoutez une propriété pour la couleur


    width: parent.width / 2 // Définir la largeur de l'élément sur la largeur de la liste
    height: width // Hauteur de l'élément
    Rectangle {
        id: rectangle
        color: parent.color // Liez la couleur du rectangle à la propriété color
        anchors.fill: parent
        anchors.margins: 10
        radius: parent.width/2 // Couleur orange
        border.color: "black" // Couleur de la bordure
        Text {
            text: "Nom : " + nomPlot // Afficher le nom du périphérique
            anchors.centerIn: parent
            font.bold: true
            topPadding: 30
        }
        Text {
            text: "0%"
            // Afficher le nom du périphérique
            anchors.centerIn: parent
            font.bold: true
        }
        Text {
            text: "ID du plot : " + idPlot
            anchors.horizontalCenter: parent.horizontalCenter // Utilisation de la propriété idPlot au lieu de id
            anchors {
                bottom: parent.bottom
                bottomMargin: 53
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
