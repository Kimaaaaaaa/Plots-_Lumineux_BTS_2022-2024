<?php
// inclure les fonctions d’accès à la base de données
require("dataJoueurs.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataJoueurs = new DataJoueurs();

// test de la méthode de la requête http
switch ($request_method) {
    case 'GET': // Si c’est une méthode GET
        // Récupérer les produits
        if (!empty($_GET["id"])) // Si la propriété id existe
        {
            $id = intval($_GET["idPartie"]);
            $reponse = $dataJoueurs->getDate(); // alors appelle de la méthode getJoueur($id)

            // création de la réponse en JSON
            header('Content-Type: application/json');
            echo json_encode($reponse, JSON_PRETTY_PRINT);
        } else {
            $reponse = $dataJoueurs->getDate(); // alors appelle de la méthode getJoueur()
            
            // création de la réponse en JSON
            header('Content-Type: application/json');
            echo json_encode(array('joueurs' => $reponse), JSON_PRETTY_PRINT);
        }
        break;

    default:
        // Requête invalide
        header("HTTP/1.0 405 Method Not Allowed");
        break;
}
?>
