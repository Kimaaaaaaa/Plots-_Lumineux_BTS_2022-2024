import QtQuick 2.15
import QtQuick.Controls 2.15
import Joueur 1.0

ApplicationWindow {
    visible: true
    width: 450
    height: 900
    title: "Mon Application"

    StackView {
        id: stackView
        initialItem: "connexionInscription.qml"
        anchors.fill: parent
    }
}
