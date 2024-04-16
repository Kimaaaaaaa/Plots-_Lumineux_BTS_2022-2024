import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    id: root
    visible: true
    width: 450
    height: 900
    title: "Inscription"

    // Propriétés
    property var tab: []
    property var db: null

    property string identifiant: ""
    property string password: ""
    property string email: ""

    // Propriété pour stocker le message d'erreur
    property string errorMessage: ""

    Component.onCompleted: {
        controller.creationJoueurReussie.connect(creationJoueurReussie);
        controller.creationJoueurEchouee.connect(creationJoueurEchouee);
    }

    function inscription() {
        controller.identifiantExiste(identifiant);
    }

    function creationJoueurReussie() {
        stackView.push("accueilApplication.qml");
    }

    function creationJoueurEchouee() {
        console.log("Identifiants incorrects. Veuillez réessayer.");
    }

    Rectangle {
        anchors.fill: parent
        color: "#BBFAFC" // Couleur de fond pour la page

        RowLayout {
            id: barreAccueilIdentification
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: qsTr("S'inscrire")
                font.pointSize: 24
                font.bold: true
                color: "#333333"
            }
        }


        ColumnLayout {
            anchors.centerIn: parent
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Text {
                id: identifiant
                text: qsTr("Identifiant")
                font.pointSize: 12
                Layout.fillWidth: true
            }

            TextField {
                id: usernameField
                placeholderText: "utilisateur"
                Layout.fillWidth: true
            }

            Text {
                id: email
                text: qsTr("Email")
                font.pointSize: 12
                Layout.fillWidth: true
            }

            TextField {
                id: emailField
                placeholderText: "exemple@gmail.com"
                Layout.fillWidth: true
            }

            Text {
                id: mdp
                text: qsTr("Mot de passe")
                font.pointSize: 12
                Layout.fillWidth: true
            }

            TextField {
                id: passwordField
                placeholderText: "*********"
                echoMode: TextInput.Password
                Layout.fillWidth: true
            }

            Text {
                id: mdpconfirme
                text: qsTr("Confirmer le mot de passe")
                font.pointSize: 12
                Layout.fillWidth: true
            }

            TextField {
                id: confirmPasswordField
                placeholderText: "**********"
                echoMode: TextInput.Password
                Layout.fillWidth: true
            }


            Text {
                text: errorMessage
                color: "red"
                font.bold: true
                visible: errorMessage !== ""
                Layout.fillWidth: true
            }

            Button {
                width: 200
                height: 50
                text: "S'inscrire"
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

                onClicked: {
                    var identifiant = usernameField.text;
                    var email = emailField.text;
                    var password = passwordField.text;
                    var confirmPassword = confirmPasswordField.text;

                    if (identifiant === "") {
                        errorMessage = "Veuillez entrer un identifiant.";
                        return;
                    }

                    if (email === "") {
                        errorMessage = "Veuillez entrer une adresse email.";
                        return;
                    }

                    if (!email.includes("@")) {
                        errorMessage = "L'adresse email est incorrecte.";
                        return;
                    }

                    if (password === "") {
                        errorMessage = "Veuillez entrer un mot de passe.";
                        return;
                    }

                    if (confirmPassword === "") {
                        errorMessage = "Veuillez confirmer votre mot de passe.";
                        return;
                    }

                    if (identifiant.length < 5 || identifiant.length > 20) {
                        errorMessage = "L'identifiant doit contenir entre 5 et 20 caractères.";
                        return;
                    }

                    if (password.length < 5 || password.length > 20) {
                        errorMessage = "Le mot de passe doit contenir entre 5 et 20 caractères.";
                        return;
                    }

                    var specialChars = /[^A-Za-z0-9]/;
                    if (!specialChars.test(password)) {
                        errorMessage = "Le mot de passe doit contenir au moins un caractère spécial.";
                        return;
                    }

                    if (password !== confirmPassword) {
                        errorMessage = "Les mots de passe ne correspondent pas.";
                        return;
                    }

                    // Utilisation des valeurs des champs de texte pour l'inscription
                    creationJoueurReussie();
                    controller.createJoueur(identifiant, password, email);

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
