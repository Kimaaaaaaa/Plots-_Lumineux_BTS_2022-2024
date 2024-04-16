import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    visible: true
    width: 450
    height: 900
    title: "Entrainement"

    property int initialTime: tempsPourAppuyer.value // Temps initial en secondes
    property int currentTime: initialTime * 1000 // Temps actuel en millisecondes
    property bool timerRunning: false // Indicateur pour savoir si le chrono est en cours
    property int nombreDePlotsChoisi: nbPlots.value
    property bool soloMode: nbJoueur.value === 1


    Component.onCompleted: {
        controller.creationPartieReussie.connect(creationPartieReussie);
        controller.creationPartieEchouee.connect(creationPartieEchouee);
    }

    function config() {
        controller.creationPartieReussie(creationPartieReussie);
    }

    function creationConfigReussie() {
        console.log("La configuration est faite");
    }

    function creationPartieEchouee() {
        console.log("ERREUR");
    }



    function formatTime(tempsPourAppuyer) {
        var secondes = Math.floor(tempsPourAppuyer / 1000);
        var millisecondes = tempsPourAppuyer % 1000;
        var minutes = Math.floor(secondes / 60);
        secondes %= 60;
        return minutes + ":" + (secondes < 10 ? "0" : "") + secondes + ":" + (millisecondes < 100 ? "0" : "") + (millisecondes < 10 ? "0" : "") + millisecondes;
    }

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"


        ColumnLayout {
            x: 115
            anchors.horizontalCenter: parent
            spacing: 20

            Text {
                text: qsTr("Entrainement")
                font.pointSize: 24
                font.bold: true
                color: "#333333"
            }
        }

        ColumnLayout {
            anchors.fill: parent
            anchors.topMargin: 20
            spacing: 20

            RowLayout {
                spacing: 10
                Layout.alignment: Qt.AlignHCenter

                Text {
                    font.pixelSize: 16
                    text: qsTr("Temps restant pour appuyer sur plot :")
                }

                Text {
                    font.pixelSize: 16
                    Layout.alignment: Qt.AlignHCenter
                    text: formatTime(currentTime)
                }
            }

            Text {
                text: soloMode ? "Mode solo" : "Mode duo"
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "Nombre de plots appareillés pour s'entraîner : " + nombreDePlotsChoisi
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter
            }

            Text {
                text: "Nombre de plots appuyés restants : " + nbPlotsAppuyes.value
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter
            }

            Button {
                id: boutonDemarrer
                Layout.alignment: Qt.AlignHCenter
                width: 200
                height: 50
                text: timerRunning ? "Pause" : "Démarrer"
                contentItem: Text {
                    text: parent.text
                    font.bold: true
                    color: "black"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                onClicked: {
                    if (timerRunning) {
                        countdownTimer.stop();

                    } else {
                        countdownTimer.start();
                    }
                    timerRunning = !timerRunning;
                }
                background: Rectangle {
                    color: "#FFB22A"
                    radius: 10
                }
            }

            Button {
                Layout.alignment: Qt.AlignHCenter
                width: 200
                height: 50
                text: "Retour"
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
        }
    }

    Timer {
        id: countdownTimer
        interval: 10
        repeat: true
        onTriggered: {
            if (timerRunning) {
                currentTime -= countdownTimer.interval;
                if (currentTime <= 0) {
                    countdownTimer.stop();
                    timerRunning = false;
                }
                timeDisplay.text = formatTime(currentTime);
            }
        }
    }
}
