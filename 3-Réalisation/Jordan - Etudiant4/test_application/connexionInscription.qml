import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    visible: true
    width: 450
    height: 900
    title: "Se connecter / s'inscrire"



    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"

    }


    GridLayout {
        anchors.fill: parent
        columns: 1
        rows: 2
        anchors.centerIn: parent



        Row {
            id: barreAccueil
            width: 640
            Layout.alignment: Qt.AlignHCenter

            Text {
                text: qsTr("Se connecter ou s'inscrire")
                font.pointSize: 24
                font.bold: true
                color: "#333333"
            }
        }

        Column {
            spacing: 20
            Layout.alignment: Qt.AlignHCenter

            Button {
                width: 200
                height: 50
                text: "Connexion"
                onClicked: {
                    if(controller.testerJoueurConnecte()){
                        stackView.push("accueilApplication.qml")
                    }else{
                        stackView.push("connexion.qml")
                    }
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
                width: 200
                height: 50
                text: "Inscription"
                onClicked: stackView.push("inscription.qml")
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
}
