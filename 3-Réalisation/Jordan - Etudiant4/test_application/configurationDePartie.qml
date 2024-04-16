import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    visible: true
    width: 450
    height: 900
    title: "Configuration"


    Component.onCompleted: {
        controller.creationConfigReussie.connect(creationConfigReussie);
        controller.creationConfigEchoue.connect(creationConfigEchoue);
    }

    function config() {
        controller.creationConfigReussie(creationConfigReussie);
    }

    function creationConfigReussie() {
        stackView.push("sEntrainer.qml");
        console.log("La configuration est faite");
    }

    function creationConfigEchoue() {
        console.log("ERREUR");
    }
    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"

        Row {
            id: barreConfiguration
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: texte
                font.pointSize: 15
                text: qsTr("Configuration de la partie")
                Layout.alignment: Qt.AlignHCenter
            }
        }

        Column {
            id: column
            anchors.horizontalCenter: parent.horizontalCenter
            y: 30
            width: 200
            height: 375
            spacing: 20

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Temps pour appuyer en secondes"
                font.pointSize: 12
            }

            SpinBox {
                id: tempsPourAppuyer
                from: 5
                to: 30
                stepSize: 5
                width: 200
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Nombre de joueur"
                font.pointSize: 12

            }

            SpinBox {
                id:nbJoueur
                from: 1
                to: 2
                width: 200
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
            }

            Text {

                anchors.horizontalCenter: parent.horizontalCenter
                text: "Nombre de plots a appuyés"
                font.pointSize: 12

            }

            SpinBox {
                id:nbPlotsAppuyes
                from: 5
                to: 30
                stepSize: 5
                width: 200
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
            }



            Text {

                anchors.horizontalCenter: parent.horizontalCenter
                text: "Nombre de plots"
                font.pointSize: 12
            }

            SpinBox {
                id:nbPlots
                value: 1
                to: 4
                width: 200
                height: 40
                anchors.horizontalCenter: parent.horizontalCenter
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Couleur du plot Joueur 1"
                font.pointSize: 12
            }

            SpinBox {
                id: couleurPlot
                from: -1
                value: 0
                width: 200
                height: 40

                property var items: ["rouge", "bleu", "vert", "jaune", "blanc"]
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
                validator: IntValidator { bottom: 0 }

                textFromValue: function(value) {
                    return items[value];
                }
            }

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Couleur du plot Joueur 2"
                font.pointSize: 12
                visible: nbJoueur.value === 2
            }

            SpinBox {
                id: couleurPlot2
                from: -1
                value: -1
                width: 200
                height: 40
                visible: nbJoueur.value === 2
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }


                property var items: ["rouge", "bleu", "vert", "jaune", "blanc"]

                validator: IntValidator { bottom: 0 }

                textFromValue: function(value) {
                    return items[value];
                }
            }
        }

        RowLayout {
            id: buttonLayout
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            anchors.bottom: parent.bottom

            Button {
                text: "Valider"
                onClicked: {

                    if (couleurPlot.value === -1 || (nbJoueur.value === 2 && couleurPlot2.value === -1)) {
                        console.log("Veuillez sélectionner la couleur des plots pour tous les joueurs.")
                    } else if (couleurPlot.value === couleurPlot2.value) {
                        console.log("Vous ne pouvez pas choisir la même couleur pour les deux joueurs.")
                    }
                        creationConfigReussie();
                        controller.createConfig(couleurPlot.textFromValue(couleurPlot.value),nbJoueur.value,nbPlots.value,tempsPourAppuyer.value,nbPlotsAppuyes.value);
                        //console.log(couleurPlot.textFromValue(couleurPlot.value));
                        console.log("Bouton de configuration de la partie appuyé");

                }

                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
                contentItem: Text {
                    text: parent.text
                    font.bold: true
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Button {
                text: "Retour"
                onClicked: stackView.push("accueilApplication.qml")
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
                contentItem: Text {
                    text: parent.text
                    font.bold: true
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }


        StackView {
            id: stackView
            anchors.fill: parent
        }



    }
}
