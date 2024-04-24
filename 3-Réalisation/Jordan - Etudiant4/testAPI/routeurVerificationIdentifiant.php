<?php
// Inclure la classe DataJoueurs
require_once 'DataJoueurs.php';

// Créer une instance de la classe DataJoueurs
$dataJoueurs = new DataJoueurs();

// Vérifier si des données POST ont été envoyées
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Récupérer l'identifiant envoyé par la requête POST
    $identifiant = $_POST['identifiant'];

    // Vérifier si l'identifiant existe déjà
    $reponse = $dataJoueurs->identifiantExiste($identifiant);

    // Retourner la réponse au format JSON
    echo json_encode($reponse);
} else {
    // Retourner une erreur si la méthode HTTP n'est pas POST
    $reponse = array('statut' => 0, 'message' => 'Méthode HTTP non autorisée');
    echo json_encode($reponse);
}
?>
