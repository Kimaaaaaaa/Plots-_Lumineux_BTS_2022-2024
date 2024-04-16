import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtCharts 2.3

Page {
    visible: true
    width: 450
    height: 900
    title: "Statistiques"

    property string date: ""
    property var statistiques

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"

        Row {
            id: barreAccueilStats
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 50
            Text {
                id: texte
                font.pointSize: 24
                font.bold: true
                text: qsTr("Statistiques")
                Layout.alignment: Qt.AlignHCenter
            }

        }

        Row {
            anchors.fill: parent
            anchors.topMargin: 35
            id:donnes


            Text {
                text: "TR J1"
                width: listView.width * 0.25
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                padding: 5
                font.pixelSize: 14
            }

            Text {
                text: "TR J2"
                width: listView.width * 0.25
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                padding: 5
                font.pixelSize: 14
            }

            Text {
                text: "Plots Appuyés"
                width: listView.width * 0.25
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                padding: 5
                font.pixelSize: 14
            }

            Text {
                text: "Date"
                width: listView.width * 0.25
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
                padding: 5
                font.pixelSize: 14
            }
        }

        ListView {
            id: listView
            spacing: 10
            anchors.top: barreAccueilStats.bottom
            anchors.bottom: retourButton.top
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            anchors.topMargin: 20


            model: ListModel {
                ListElement { date: "02/01/2024"; tempsReactionJ1: "15s"; tempsReactionJ2: "0s"; plotsAppuyes: "12" }
                ListElement { date: "03/01/2024"; tempsReactionJ1: "12s"; tempsReactionJ2: "18s"; plotsAppuyes: "8" }
                ListElement { date: "03/01/2024"; tempsReactionJ1: "12s"; tempsReactionJ2: "18s"; plotsAppuyes: "8" }
            }

            delegate: Button {
                width: listView.width
                height: 60
                onClicked: {
                    console.log("bouton date cliqué:", model.date);
                    stackView.push("afficherLesStatistiques.qml");
                }

                background: Rectangle {
                    color: index % 2 === 0 ? "#FFFFFF" : "#FAFAFA"
                }
                Row {
                    anchors.fill: parent

                    Text {
                        text: model.tempsReactionJ1
                        width: listView.width * 0.25
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                        padding: 5 // Réduire le padding
                        font.pixelSize: 14 // Réduire la taille de la police
                    }

                    Text {
                        text: model.tempsReactionJ2
                        width: listView.width * 0.25
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                        padding: 5
                        font.pixelSize: 14
                    }

                    Text {
                        text: model.plotsAppuyes
                        width: listView.width * 0.25
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignLeft
                        padding: 5
                        font.pixelSize: 14
                    }

                    Text {
                        text: model.date
                        width: listView.width * 0.25
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignRight
                        padding: 5
                        font.pixelSize: 14
                        color: "blue"
                    }
                }
                font.family: texte.font.family
            }
        }

        Button {
            id: retourButton
            text: "Retour"
            font.bold: true
            onClicked: {
                stackView.push("accueilApplication.qml");
            }
            background: Rectangle {
                color: "#FFB22A"
                radius: 10
            }
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 16
        }

        Button {
            id: afficherMoyenneButton
            text: "Afficher Moyenne"
            font.bold: true
            onClicked: {
                stackView.push("afficherMoyenne.qml");
            }
            background: Rectangle {
                color: "#FFB22A"
                radius: 10
            }
            anchors {
                bottom: retourButton.top
                horizontalCenter: parent.horizontalCenter
                bottomMargin: 10
            }
            font.pixelSize: 16
        }
    }
}
