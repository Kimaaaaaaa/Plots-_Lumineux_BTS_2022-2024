<?php
// inclure les fonctions d’accès à la base de données
require("dataJoueurs.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataJoueurs = new DataJoueurs();

// test de la méthode de la requête http
switch ($request_method) {
    case 'POST': // Si c’est une méthode POST
        // Récupérer les produits
        $identifiant = isset($_POST['identifiant']) ? $_POST['identifiant'] : '';
        $password = isset($_POST['password']) ? $_POST['password'] : '';

        if (empty($identifiant) || empty($password)) {
            $reponse = array('statut' => 0, 'message' => 'Identifiant ou mot de passe non fourni');
        } else {
            $reponse = $dataJoueurs->connexionJoueur($identifiant, $password);
        }

        // création de la réponse en JSON
        header('Content-Type: application/json');
        echo json_encode($reponse, JSON_PRETTY_PRINT);
        break;

    default:
        // Requête invalide
        header("HTTP/1.0 405 Method Not Allowed");
        break;
}
?>
