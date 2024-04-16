import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.LocalStorage 2.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    color: "#BBFAFC"
    title: "Connexion"

    property string email: ""
    property string username: ""
    property string password: ""
    property string passwordconfirm: ""

    property var db: null
    property var tab: []

    // Fonction pour ouvrir la base de données
    function openDatabase() {
        db = LocalStorage.openDatabaseSync("plots_lumineux", "1.0", "Database for plots lumineux", 1000000);
        if (!db) {
            console.error("Error opening database");
        } else {
            console.log("Database opened successfully");
        }
    }

    function recevoirDonneesJoueur(password, identifiant) {
        var joueur = null;
        db.transaction(function(tx) {
            var res = tx.executeSql("SELECT * FROM joueurs WHERE identifiant = ? AND password = ?", [identifiant, password]);
            if (res.rows.length > 0) {
                joueur = {
                    identifiant: res.rows.item(0).identifiant,
                    password: res.rows.item(0).password
                };
            }
        });
        return joueur;
    }


    GridLayout {
        anchors.fill: parent
        columns: 1
        rows: 2
        anchors.centerIn: parent

        RowLayout {
            id: barreAccueilConnexion
            width: 640
            Layout.alignment: Qt.AlignHCenter

            Text {
                id: texte
                font.pointSize: 15
                text: qsTr("Se connecter")
                Layout.alignment: Qt.AlignHCenter
            }
        }

        Column {
            spacing: 10
            Layout.alignment: Qt.AlignHCenter

            Text {
                id: identifiant
                text: qsTr("Identifiant")
                font.pointSize: 12
            }

            TextField {
                placeholderText: "Identifiant"
                text: username
                onTextChanged: username = text.trim()
            }

            Text {
                id: mdp
                text: qsTr("Mot de passe")
                font.pointSize: 12
            }

            TextField {
                placeholderText: "********"
                text: password
                echoMode: TextInput.Password
                onTextChanged: password = text.trim()
            }

            Button {
                text: "Connexion"
                onClicked: {
                    if (username === "" || password === "") {
                        console.log("Veuillez remplir tous les champs.");
                        tab[0] = 0;
                        return; // Retour anticipé si les champs ne sont pas remplis
                    }

                    var joueur = recevoirDonneesJoueur(password, username);
                    if (joueur === null) {
                        console.log("Identifiant ou mot de passe incorrect.");
                        return; // Retour anticipé si les identifiants sont incorrects
                    }

                    // Si les identifiants sont corrects, afficher un message de connexion réussie et changer de vue
                    recevoirDonneesJoueur(password,username);
                    stackView.push("accueilApplication.qml");
                    console.log("Connexion réussie pour l'utilisateur :", username);
                }

                background: Rectangle {
                    color: parent.down ? "#FFB22A" : (parent.hovered ? "#FFB22A" : "#FFB22A")
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: null
        anchors.fill: parent
    }

    function openDatabase() {
        db = LocalStorage.openDatabaseSync("plots_lumineux", "1.0", "Database for plots lumineux", 1000000);
        if (!db) {
            console.error("Error opening database");
        } else {
            console.log("Database opened successfully");
        }
    }
}
