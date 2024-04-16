<?php
// inclure les fonctions d’accès à la base de données
require("dataResultats.php");

// Récupérer le verbe (méthode http) de la requête
$request_method = $_SERVER["REQUEST_METHOD"];

$dataResultats = new DataResultats();

// test de la méthode de la requête http
switch ($request_method) {
    case 'POST': // Si c’est une méthode POST
        // Récupérer les données POST
        $couleurPlot = isset($_POST['couleurPlot']) ? $_POST['couleurPlot'] : '';
        $nbJoueur = isset($_POST['nbJoueur']) ? $_POST['nbJoueur'] : '';
        $nbPlots = isset($_POST['nbPlots']) ? $_POST['nbPlots'] : '';
        $tempsPourAppuyer = isset($_POST['tempsPourAppuyer']) ? $_POST['tempsPourAppuyer'] : '';
        $nbPlotsAppuyes = isset($_POST['nbPlotsAppuyes']) ? $_POST['nbPlotsAppuyes'] : '';

        if ($couleurPlot != '' && $nbJoueur != '' && $nbPlots != '' && $tempsPourAppuyer != '' && $nbPlotsAppuyes != '') {
            // Appel de la méthode createConfig avec les données POST
            $reponse = $dataResultats->createConfig($couleurPlot, $nbJoueur, $nbPlots,$tempsPourAppuyer,$nbPlotsAppuyes);
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