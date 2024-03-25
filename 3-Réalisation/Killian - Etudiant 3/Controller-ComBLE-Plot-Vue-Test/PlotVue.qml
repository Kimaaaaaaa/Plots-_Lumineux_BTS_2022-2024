import QtQuick 2.15
import QtQuick.Controls 2.15

Item{

    property string nomPlot
    property int nvBatteriePlot
    property bool selectedPlot

    width: parent.width // Définir la largeur de l'élément sur la largeur de la liste
    height: 60 // Hauteur de l'élément
    Rectangle {
        width: parent.width
        height: parent.height
        color: selectedPlot?"#FFB22A":"#00B000" // Couleur orange
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
        Text{
            text: "ID du plot : " + controller.getIdPlot()


        }


        MouseArea {
            anchors.fill: parent
            onClicked: {
                var idPlot = controller.getIdPlot()

                console.log("Vous avez ajouté le plot : " + idPlot)

                // Appeler la fonction pour effectuer le couplage du plot
                controller.couplerPlot(idPlot)

                selectedPlot = !selectedPlot;
            }
        }

    }
}

