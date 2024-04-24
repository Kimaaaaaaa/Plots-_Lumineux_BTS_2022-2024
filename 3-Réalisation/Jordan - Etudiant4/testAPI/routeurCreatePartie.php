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
        $date = isset($_POST['date']) ? $_POST['date'] : '';
        $tempsReactionJ1 = isset($_POST['temps$tempsReactionJ1']) ? $_POST['temps$tempsReactionJ2'] : '';
        $tempsReactionJ2 = isset($_POST['tempsReactionJ2']) ? $_POST['tempsReactionJ2'] : '';

        if ($date != '' && $tempsReactionJ1 != '' && $tempsReactionJ2 != '') {
            // Appel de la méthode createJoueur avec les données POST
            $reponse = $dataJoueurs->createJoueur($date, $tempsReactionJ1, $tempsReactionJ2);
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
