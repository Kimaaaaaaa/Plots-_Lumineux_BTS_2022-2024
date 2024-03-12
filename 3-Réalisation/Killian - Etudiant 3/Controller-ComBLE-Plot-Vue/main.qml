import QtQuick 2.15
import QtQuick.Controls 2.15

import entitePlot 1.0

ApplicationWindow {
    visible: true
    width: 450
    height: 900
    title: "Detection de Plots"



    // Définir un modèle de bouton pour détecter les plots
    Button {
        id: detectButton
        text: "Détecter les plots"
        anchors {
            bottom: parent.bottom  // Ancre le bas du bouton au bas de la fenêtre
            horizontalCenter: parent.horizontalCenter  // Centre horizontalement le bouton dans la fenêtre
        }

        onClicked: {
            // Afficher un message dans la console lorsque le bouton est cliqué
            console.log("Bouton cliqué");
            comBLE.startScanning();
        }

        // Handle the device discovered signal
        /*onDeviceDiscovered: {
            // Create a rectangle to display the device name
            var deviceRect = Qt.createQmlObject('import QtQuick 2.15; Rectangle { width: 200; height: 50; color: "lightgreen"; border.color: "green"; radius: 5; Text { anchors.centerIn: parent; text: info.name; } }', detectButton);

            // Position the rectangle relative to the ApplicationWindow
            deviceRect.x = (ApplicationWindow.width - deviceRect.width) / 2;
            deviceRect.y = ApplicationWindow.height - deviceRect.height - 100; // Adjust position as needed
        }*/
    }

    ListView {
        id: listView
        anchors.fill: parent
        anchors.bottomMargin: 46
        model: controller.listePlots
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1

                Text {
                    text: nvBatterie
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }
}
