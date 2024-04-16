import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    visible: true
    width: 450
    height: 900
    title: "Connexion"

    property string identifiant: ""
    property string password: ""
    property bool resterConnecte: false // Nouvelle propriété pour garder l'utilisateur connecté

    property string errorMessage: ""

    Component.onCompleted: {

            controller.connexionJoueurReussie.connect(connexionReussie);
            controller.connexionJoueurEchoue.connect(connexionEchouee);

    }

    function login() {
        errorMessage = "";
        controller.connexionJoueur(identifiant, password);
    }


    function connexionReussie() {
        stackView.push("accueilApplication.qml");
    }

    function connexionEchouee() {
        errorMessage = "Identifiants incorrects. Veuillez réessayer.";
    }

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC"

        RowLayout {
            id: barreAccueilIdentification
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                text: qsTr("Se connecter")
                font.pointSize: 24
                font.bold: true
                color: "#333333"
            }
        }

        Column {
            spacing: 40
            anchors.centerIn: parent

            TextField {
                placeholderText: "Identifiant"
                text: identifiant
                onTextChanged: identifiant = text.trim()
            }

            TextField {
                placeholderText: "********"
                text: password
                echoMode: TextInput.Password
                onTextChanged: password = text.trim()
            }



            Text {
                text: errorMessage
                color: "red"
                font.bold: true
                visible: errorMessage !== ""
            }

            RowLayout {
                spacing: 20

                Button {
                    width: 200
                    height: 50
                    text: "Connexion"
                    onClicked:
                    {

                        if (identifiant === "" || password === "") {
                            errorMessage = "Veuillez remplir tous les champs.";
                            return;
                        }

                        else
                        {
                        //connexionReussie();
                        controller.connexionJoueur(identifiant,password);
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
    }
}
