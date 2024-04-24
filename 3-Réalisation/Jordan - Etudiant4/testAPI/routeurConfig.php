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
        $couleurPlot = isset($_POST['couleurPlot']) ? $_POST['couleurPlot'] : '';
        $nbJoueur = isset($_POST['temps$nbJoueur']) ? $_POST['temps$nbPlot'] : '';
        $tempsPourAppuyer = isset($_POST['tempsPourAppuyer']) ? $_POST['tempsPourAppuyer'] : '';
        $nbPlot = isset($_POST['nbPlot']) ? $_POST['nbPlot'] : '';
        $nbPlotsAppuyes = isset($_POST['nbPlotsAppuyes']) ? $_POST['nbPlotsAppuyes'] : '';
        


        if ($couleurPlot != '' && $nbJoueur != '' && $nbPlot != '' && $tempsPourAppuyer != '' && $nbPlotsAppuyes != '') {
            // Appel de la méthode createJoueur avec les données POST
            $reponse = $dataJoueurs->createJoueur($couleurPlot, $nbJoueur, $nbPlot);
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