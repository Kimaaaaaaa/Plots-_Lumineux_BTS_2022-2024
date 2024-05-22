<?php

class plots_lumineux {

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

    public function getJoueurs(){

        //initialisation de la réponse
        $reponse = array('statut'=>1,'message'=>'ok');    //1 pour validée
        
        //connexion à la BDD
        if(!$this->connexionBDD()){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'connexion bdd impossible';

            return $reponse;
        }

        //création de la requete
        $sql = 'SELECT * FROM joueurs';
        //echo $sql;

        //exécution de la requete
        $res = $this->bdd->query($sql);

        //vérification de l'exécution de la requete
        if($res == false){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Requete erronée';

            return $reponse;
        }

        //extraction des données
        $donnees = $res->fetchAll(PDO::FETCH_ASSOC);
        //var_dump($donnees);

        //attribution des données à la réponse
        $reponse['data'] = $donnees;

        return $reponse;

    }

    public function getjoueur ($id){

        //initialisation de la réponse
        $reponse = array('statut'=>1,'message'=>'ok');    //1 pour validée
                
        //connexion à la BDD
        if(!$this->connexionBDD()){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'connexion bdd impossible';

            return $reponse;
        }

        //création de la requete
        $sql = 'SELECT * FROM joueurs WHERE id='.$id;
        //echo $sql;

        //exécution de la requete
        $res = $this->bdd->query($sql);

        //vérification de l'exécution de la requete
        if($res == false){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Requete erronée';

            return $reponse;
        }

        //extraction des données
        $donnees = $res->fetch(PDO::FETCH_ASSOC);
        //var_dump($donnees);

        //attribution des données à la réponse
        $reponse['data'] = $donnees;

        return $reponse;


    }

    public function createjoueur($joueur){
        //initialisation de la réponse
        $reponse = array('statut'=>1,'message'=>'ok');    //1 pour validée
                
        //connexion à la BDD
        if(!$this->connexionBDD()){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'connexion bdd impossible';

            return $reponse;
        }

        //création de la requete
        $sql = 'INSERT INTO joueurs (password, email)
                VALUES ("'.$joueur['password'].'","'.$joueur['email'].'","'.$joueur['identifiant'].'")';
        //echo $sql;

        //exécution de la requete
        $res = $this->bdd->exec($sql);

        //vérification de l'exécution de la requete
        if($res === false){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Requete erronée';

            return $reponse;
        } else if($res === 0){  //si aucun joueur ajouté
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Non ajouté';

            return $reponse;
        }

        //récupérer le joueur créé
        $joueur['id'] = intval($this->bdd->lastInsertId());

        //attribution des données à la réponse
        $reponse['data'] = $joueur;

        return $reponse;

    }

    public function updateJoeur($joueur){

        //initialisation de la réponse
        $reponse = array('statut'=>1,'message'=>'ok');    //1 pour validée
                
        //connexion à la BDD
        if(!$this->connexionBDD()){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'connexion bdd impossible';

            return $reponse;
        }

        //création de la requete
        $sql = 'UPDATE joueurs 
                SET password = "'.$joueur['password'].'", email="'.$joueur['email'].'" 
                WHERE id='.$joueur['id'];
        //echo $sql;

        //exécution de la requete
        $res = $this->bdd->exec($sql);

        //vérification de l'exécution de la requete
        if($res === false){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Requete erronée';

            return $reponse;
        } else if($res === 0){  //si aucun joueur ajouté
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Non modifié';

            return $reponse;
        }

        //attribution des données à la réponse
        $reponse['data'] = $joueur;

        return $reponse;


    }

    public function deletJoueur($id){
        //initialisation de la réponse
        $reponse = array('statut'=>1,'message'=>'ok');    //1 pour validée
                        
        //connexion à la BDD
        if(!$this->connexionBDD()){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'connexion bdd impossible';

            return $reponse;
        }

        //création de la requete
        $sql = 'DELETE FROM joueurs 
                WHERE id='.$id;
        //echo $sql;

        //exécution de la requete
        $res = $this->bdd->exec($sql);

        //vérification de l'exécution de la requete
        if($res === false){
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Requete erronée';

            return $reponse;
        } else if($res === 0){  //si aucun joueur ajouté
            $reponse['statut'] = 0; //erreur
            $reponse['message'] = 'Non supprimé';

            return $reponse;
        }

        //attribution des données à la réponse
        $reponse['data'] = $id;

        return $reponse;

    }

}

