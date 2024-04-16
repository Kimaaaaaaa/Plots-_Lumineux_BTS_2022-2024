import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("S'identifier/se connecter")

    Label {
        text: qsTr("S'inscrire")
        anchors.centerIn: parent
    }
    Label {
        text: qsTr("Se connecter")
        anchors.verticalCenterOffset: -67
        anchors.horizontalCenterOffset: 1
        anchors.centerIn: parent
    }

    Row {
        id: connexion
        x: 0
        y: 114
        width: 600
        height: 39
    }

    Row {
        id: row
        x: 0
        y: 177
        width: 600
        height: 45
    }
}
