import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Page {
    visible: true
    width: 450
    height: 900
    title: "Accueil application"




        Rectangle {
            anchors.fill: parent
            color: "#BBFAFC"

            RowLayout {
                id: barreAccueilIdentification
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                    text: qsTr("Accueil")
                    font.pointSize: 24
                    font.bold: true
                    color: "#333333"
                }
            }

            Column{
                spacing: 40
                anchors.centerIn: parent

                Button {
                    width: 200
                    height: 50
                    text: "Afficher les  résultats"
                    onClicked: stackView.push("afficherLesResultats.qml")
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
                    width: 200
                    height: 50
                    text: "Appareiller plot(s)"
                    onClicked: stackView.push("appareillerLesPlots.qml")
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
                    width: 200
                    height: 50
                    text: "S'entrainer"
                    onClicked: stackView.push("configurationDePartie.qml")
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
                    width: 200
                    height: 50
                    text: "État des plots"
                    onClicked: console.log("Bouton d'état des plots")
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

                // Bouton de retour en arrière
                Button {
                    width: 200
                    height: 50
                    text: "Retour"
                    onClicked: stackView.push("connexionInscription.qml")
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
        }


    StackView {
        id: stackView
        initialItem: null
        anchors.fill: parent
    }
}
