<?php
// inclure les fonctions d’accès à la base de données
require("dataJoueurs.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataJoueurs = new DataJoueurs();

// test de la méthode de la requête http
switch ($request_method) {
    case 'POST': // Si c’est une méthode POST
        // Récupérer les données POST
        $identifiant = isset($_POST['identifiant']) ? $_POST['identifiant'] : '';
        $password = isset($_POST['password']) ? $_POST['password'] : '';
        $email = isset($_POST['email']) ? $_POST['email'] : '';

        if ($identifiant != '' && $password != '' && $email != '') {
            // Appel de la méthode createJoueur avec les données POST
            $reponse = $dataJoueurs->createJoueur($identifiant, $password, $email);
            echo json_encode($reponse);
        } else {
            // Si certaines données ne sont pas définies, renvoyer une erreur
            $reponse = array('statut' => 0, 'message' => 'Certains champs ne sont pas définis');
            header('Content-Type: application/json');
            http_response_code(400); // Mauvaise requete
            echo json_encode($reponse);
        }
        break;

    default:
        // Requête invalide
        header("HTTP/1.0 405 Method Not Allowed");
        break;
}
?>
