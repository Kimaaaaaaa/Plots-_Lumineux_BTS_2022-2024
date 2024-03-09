import QtQuick
import QtQuick.Controls

Window {
    width: 300
    height: 400
    visible: true
    title: qsTr("Convertisseur Euro en Franc")

    Rectangle{
        anchors.fill: parent
        color: "yellow"
    }

    Column {
        spacing: 10
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            topMargin: 50 // Ajout de marge pour éviter la superposition avec le titre de la fenêtre
            bottomMargin: 15
        }

        Row {
            spacing: 10
            TextField {
                id: saisieMonnaie1
                placeholderText: "Montant en euros"
                width: parent.width / 2
            }
            Text {
                text: "€"
                color: "darkred"
            }
        }

        Row {
            spacing: 10
            TextField {
                id: saisieMonnaie2
                placeholderText: "Montant en francs"
                width: parent.width / 2
            }
            Text {
                text: "F"
                color: "darkred"
            }
        }
    }
}
