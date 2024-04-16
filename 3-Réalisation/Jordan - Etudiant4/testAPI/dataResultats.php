<?php

class DataResultats {

    private $bdd=NULL;

    public function __construct(){

    }

    private function connexionBDD(){
        
        try{
            $this->bdd = new PDO('mysql:host=localhost;dbname=plots_lumineux', 'root', '');
            return true;
        }catch (Exception $e){
            return false;
        }
    }




    public function createConfig($couleurPlot, $nbJoueur, $nbPlots, $tempsPourAppuyer, $nbPlotsAppuyes) {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok'); // 1 pour validée
    
        // Connexion à la BDD
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        // Création de la requête
        $sql = 'INSERT INTO configpartie (couleurPlot, nbJoueur, nbPlots, tempsPourAppuyer, nbPlotsAppuyes) VALUES ("'.$couleurPlot.'", "'.$nbJoueur.'", "'.$nbPlots.'", "'.$tempsPourAppuyer.'", "'.$nbPlotsAppuyes.'")';
        $s = $this->bdd->prepare($sql);
        
        // Exécution de la requête
        $res = $s->execute([$couleurPlot, $nbJoueur, $nbPlots, $tempsPourAppuyer, $nbPlotsAppuyes]);
    
        // Vérification de l'exécution de la requête
        if ($res === false) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Requête erronée';
            return $reponse;
        } else if ($res === 0) { // Si aucun config ajouté
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Non ajouté';
            return $reponse;
        }
    
        // Récupérer l'ID du config créé
        $reponse['idPartie'] = intval($this->bdd->lastInsertId());
    
        // Attribution des données à la réponse
        return $reponse;
    }





    public function createPartie($date, $tempsReactionJ1,$joueur1_id) {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok'); // 1 pour validée
    
        // Connexion à la BDD
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        // Création de la requête
        $sql = 'INSERT INTO partie (date, tempsReactionJ1, joueur1_id) VALUES ("'.$date.'", "'.$tempsReactionJ1.'", "'.$joueur1_id.'")';
        $s = $this->bdd->prepare($sql);
        
        // Exécution de la requête
        $res = $s->execute([$date, $tempsReactionJ1, $joueur1_id]);
    
        // Vérification de l'exécution de la requête
        if ($res === false) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Requête erronée';
            return $reponse;
        }
    
        // Attribution des données à la réponse
        return $reponse;
    }

}
