import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



Window {
    width: 640
    height: 480
    visible: true
    color:"#BBFAFC"
    title: qsTr("Hello World")



    /* Première ligne */
    Row {
        id: row
        x: 19
        y: 26
        width: 600
        height: 83
        spacing : 220

        Rectangle{
            width: 50
            height: 50
            color: "#BBFAFC"

            Image{
                anchors.fill: parent // La taille de l'image est définie pour remplir le rectangle
                source: "maison.png" // Chemin de l'image
                fillMode: Image.PreserveAspectFit
            }
        }


        Text{

            text:"Etats des plots"
        }

        Rectangle{
            width: 50
            height: 50
            color: "#BBFAFC"


            Image{
                anchors.fill: parent // La taille de l'image est définie pour remplir le rectangle
                source: "user.png"
                anchors.rightMargin: 19
                anchors.bottomMargin: 0
                anchors.leftMargin: -19
                anchors.topMargin: 0 // Chemin de l'image
                fillMode: Image.PreserveAspectFit
            }

        }
    }

    /*Deuxième ligne*/

    Row {
        id: row1
        x: 19
        y: 110
        width: 608
        height: 52
        spacing : 70

        Rectangle{
            width: 50
            height: 50
            color: "#BBFAFC"
            Image {
                id: image
                x: 38
                y: 104
                anchors.fill: parent
                source: "bluetooth.png"
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                fillMode: Image.PreserveAspectFit
            }

        }
        Slider {
            id: slider
            width: 483
            height: 40
            value: 0.5
        }




    }

    Row {
        id: row2
        x: 207
        y: 414
        width: 214
        height: 52

        Rectangle{
            anchors.fill: parent
            color:"#ffb22a"
            border.width: 3

            Text{
                x: 62
                y: 20
                text:"Appareiller un plot"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    bluetoothCom.startScan(); // Démarrage du scan lorsque le bouton est cliqué
                }

            }

        }
    }

    Row {
        id: row3
        x: 19
        y: 174
        width: 608
        height: 52
        spacing: 70
        Rectangle {
            width: 50
            height: 50
            color: "#bbfafc"
        }


    }

    Row {
        id: row4
        x: 24
        y: 251
        width: 608
        height: 52
        spacing: 70
        Rectangle {
            width: 50
            height: 50
            color: "#bbfafc"
        }
    }

    Row {
        id: row5
        x: 19
        y: 328
        width: 608
        height: 52
        spacing: 70
        Rectangle {
            width: 50
            height: 50
            color: "#bbfafc"
        }
    }







}
