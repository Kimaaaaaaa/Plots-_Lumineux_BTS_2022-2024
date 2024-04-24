<?php
// inclure les fonctions d’accès à la base de données
require("dataJoueurs.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataJoueurs = new DataJoueurs();

// test de la méthode de la requête http
switch ($request_method) {
    case 'GET': // Si c’est une méthode GET
        // Récupérer les statistiques
        if (!empty($_GET["idPartie"])) // Si la propriété idPartie existe
        {
            $idPartie = intval($_GET["idPartie"]);
            $reponse = $dataJoueurs->getStatistiques($idPartie); // alors appelle de la méthode getStatistiques($idPartie)

            // création de la réponse en JSON
            header('Content-Type: application/json');
            echo json_encode($reponse, JSON_PRETTY_PRINT);
        } else {
            $reponse = $dataJoueurs->getStatistiques(); // alors appelle de la méthode getStatistiques()
            
            // création de la réponse en JSON
            header('Content-Type: application/json');
            echo json_encode(array('partie' => $reponse), JSON_PRETTY_PRINT);
        }
        break;

    default:
        // Requête invalide
        header("HTTP/1.0 405 Method Not Allowed");
        break;
}
?>
