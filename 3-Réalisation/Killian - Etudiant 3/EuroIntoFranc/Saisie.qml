import QtQuick
import QtQuick.Controls 2.3

Item {
    width: 300
    height: 50
    property alias symbole: textSymbole.text
    Text{
        id: textSymbole
        text: "€"
        anchors.left: parent.left // Ancrer à 5 pixels de la gauche
        anchors.top: parent.top // Ancrer à 5 pixels du haut
        anchors.leftMargin: 5 // Marge de 5 pixels à gauche
        anchors.topMargin: 5 // Marge de 5 pixels en haut
        color: "darkred"

    }

    TextField{
        property alias valeur: saisieValeur.text
        id: saisieValeur
        anchors.fill: parent // Définit les ancrages pour remplir le parent
        text : "0"
        font.pixelSize : 16 //Définit la taille de la police
        leftPadding: 30

    }
}
