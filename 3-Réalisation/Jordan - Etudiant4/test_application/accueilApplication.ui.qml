import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    title: qsTr("Accueil Application")




    Label {
        text: qsTr("page d'accueil")
        styleColor: "#ffffff"
        anchors.centerIn: parent
    }

    Rectangle {
        id: pageAccueil
        x: 0
        y: 0
        width: 600
        height: 400
        visible: true
        color: "#bbfafc"
    }
}
