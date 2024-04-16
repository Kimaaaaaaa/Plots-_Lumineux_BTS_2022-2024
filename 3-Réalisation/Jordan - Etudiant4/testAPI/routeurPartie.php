<?php
// inclure les fonctions d’accès à la base de données
require("dataJoueurs.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataJoueurs = new DataJoueurs();

// test de la méthode de la requête http
switch ($request_method) {
    case 'GET': // Si c’est une méthode GET
        // Récupérer les données du joueur
        if (!empty($_GET["idPartie"])) // Si la propriété id existe
        {
            $idPartie = intval($_GET["idPartie"]);
            $reponse = $dataJoueurs->getUnePartie($idPartie); // Appel de la méthode getUnePartie($id)

            // Vérification si le joueur est trouvé
            if ($reponse['statut'] == 1) {
                // création de la réponse en JSON
                header('Content-Type: application/json');
                echo json_encode($reponse, JSON_PRETTY_PRINT);
            } else {
                // Si le joueur n'est pas trouvé, renvoyer un message d'erreur
                header("HTTP/1.0 404 Not Found");
                echo json_encode($reponse, JSON_PRETTY_PRINT);
            }
        } else {
            // Si aucun identifiant de joueur n'est fourni, renvoyer un message d'erreur
            header("HTTP/1.0 400 Bad Request");
            echo json_encode(array("message" => "Choisir une id partie"), JSON_PRETTY_PRINT);
        }
        break;

    default:
        // Requête invalide
        header("HTTP/1.0 405 Method Not Allowed");
        break;
}
?>