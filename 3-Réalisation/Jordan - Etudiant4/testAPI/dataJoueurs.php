<?php

class DataJoueurs {

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















    public function getJoueur($id) {
        $reponse = array('statut' => 1, 'message' => 'ok');
    
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        try {
            // Préparation de la requête
            $sql = 'SELECT * FROM joueurs WHERE id = :id';
            $s = $this->bdd->prepare($sql);
            $s->bindParam(':id', $id, PDO::PARAM_INT);
            
            // Exécution de la requête
            $s->execute();
    
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucun joueur trouvé pour cet ID';
                return $reponse;
            }
    
            // Extraction des données
            $donnees = $s->fetch(PDO::FETCH_ASSOC);
    
            // Attribution des données à la réponse
            $reponse['joueur'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
    
        return $reponse;
    }
















    public function createJoueur($identifiant, $password, $email) {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok'); // 1 pour validée
        
        // Connexion à la BDD
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
        
        // Vérifier si l'identifiant existe déjà
        $sql_check = 'SELECT COUNT(*) AS count FROM joueurs WHERE identifiant = "'.$identifiant.'"';
        $res_check = $this->bdd->query($sql_check);
        $row = $res_check->fetch();
        
        if ($row['count'] > 0) {
            // L'identifiant existe déjà, renvoyer une erreur
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Identifiant déjà utilisé';
            return $reponse;
        }
        
        // Création de la requête
        $sql = 'INSERT INTO joueurs (identifiant, password, email) VALUES ("'.$identifiant.'", "'.$password.'", "'.$email.'")';
        
        // Exécution de la requête
        $res = $this->bdd->exec($sql);
        
        // Vérification de l'exécution de la requête
        if ($res === false) {
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Requête erronée';
            return $reponse;
        } else if ($res === 0) { // Si aucun joueur ajouté
            $reponse['statut'] = 0; // Erreur
            $reponse['message'] = 'Non ajouté';
            return $reponse;
        }
        
        // Récupérer le joueur créé
        $reponse['id'] = intval($this->bdd->lastInsertId());
        
        // Attribution des données à la réponse
        return $reponse;
    }







    
    
    
















    public function connexionJoueur($identifiant, $password) {
        $reponse = array('statut' => 1, 'message' => 'ok');

        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }


        try {
            // Préparation de la requête

            $sql = 'SELECT * FROM joueurs WHERE identifiant = :identifiant AND password = :password';
            $s = $this->bdd->prepare($sql);
            $s->bindParam(':identifiant', $identifiant, PDO::PARAM_STR);
            $s->bindParam(':password', $password, PDO::PARAM_STR);

            // Exécution de la requête
            $s->execute();

            // Vérification de l'exécution de la requête
            if (!isset($_POST['identifiant']) || !isset($_POST['password'])) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Identifiant ou mot de passe non fourni';
                return $reponse;
            }

            $identifiant = $_POST['identifiant'];
            $password = $_POST['password'];
        
            // Extraction des données du joueur
            $donnees = $s->fetch(PDO::FETCH_ASSOC);

            // Attribution des données à la réponse
            $reponse['joueur'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }

        return $reponse;
    }








    public function identifiantExiste($identifiant) {
        $reponse = array('statut' => 1, 'message' => 'ok');
    
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        try {
            // Préparation de la requête
            $sql = 'SELECT COUNT(*) AS count FROM joueurs WHERE identifiant = :identifiant';
            $s = $this->bdd->prepare($sql);
            $s->bindParam(':identifiant', $identifiant, PDO::PARAM_STR);
    
            // Exécution de la requête
            $s->execute();
    
            // Récupération du résultat
            $resultat = $s->fetch(PDO::FETCH_ASSOC);
    
            // Vérification si l'identifiant existe déjà
            if ($resultat['count'] > 0) {
                $reponse['statut'] = 1;
                $reponse['message'] = 'L\'identifiant existe déjà';
            } else {
                $reponse['statut'] = 0;
                $reponse['message'] = 'L\'identifiant n\'existe pas';
            }
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
    
        return $reponse;
    }
    












    public function getStatistiques() {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok', 'statistiques' => array());
        
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
        
        try {
            // Préparation de la requête pour obtenir les statistiques
            $sql = 'SELECT * FROM partie';
            $s = $this->bdd->prepare($sql);
            
            // Exécution de la requête
            $s->execute();
        
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucune statistique disponible';
                return $reponse;
            }
        
            // Extraction des données
            $donnees = $s->fetchAll(PDO::FETCH_ASSOC);
        
            // Attribution des données à la réponse
            $reponse['statistiques'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
        
        return $reponse;
    }









    public function getStatistiquesUnjoueur($identifiant) {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok', 'statistiques' => array());
        
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
        
        try {
            // Préparation de la requête pour obtenir les statistiques
            $sql = 'SELECT * FROM partie WHERE identifiant = :identifiant';
            $s = $this->bdd->prepare($sql);
            
            // Exécution de la requête
            $s->execute();
        
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucune statistique disponible';
                return $reponse;
            }
        
            // Extraction des données
            $donnees = $s->fetchAll(PDO::FETCH_ASSOC);
        
            // Attribution des données à la réponse
            $reponse['statistiques'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
        
        return $reponse;
    }















    public function getUnTour($id) {
        $reponse = array('statut' => 1, 'message' => 'ok');
    
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        try {
            // Préparation de la requête
            $sql = 'SELECT * FROM tour WHERE id = :id';
            $s = $this->bdd->prepare($sql);
            $s->bindParam(':id', $id, PDO::PARAM_INT);
            
            // Exécution de la requête
            $s->execute();
    
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucun joueur trouvé pour cet ID';
                return $reponse;
            }
    
            // Extraction des données
            $donnees = $s->fetch(PDO::FETCH_ASSOC);
    
            // Attribution des données à la réponse
            $reponse['tour'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
    
        return $reponse;
    }






    public function getUnePartie($idPartie) {
        $reponse = array('statut' => 1, 'message' => 'ok');
    
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        try {
            // Préparation de la requête
            $sql = 'SELECT * FROM partie WHERE idPartie = :idPartie';
            $s = $this->bdd->prepare($sql);
            $s->bindParam(':idPartie', $idPartie, PDO::PARAM_INT);
            
            // Exécution de la requête
            $s->execute();
    
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucun partie trouvé pour cet ID';
                return $reponse;
            }
    
            // Extraction des données
            $donnees = $s->fetch(PDO::FETCH_ASSOC);
    
            // Attribution des données à la réponse
            $reponse['joueur'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
    
        return $reponse;
    }












    public function getTours() {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok', 'statistiques' => array());
        
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
        
        try {
            // Préparation de la requête pour obtenir les statistiques
            $sql = 'SELECT * FROM tour';
            $s = $this->bdd->prepare($sql);
            
            // Exécution de la requête
            $s->execute();
        
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucune statistique disponible';
                return $reponse;
            }
        
            // Extraction des données
            $donnees = $s->fetchAll(PDO::FETCH_ASSOC);
        
            // Attribution des données à la réponse
            $reponse['statistiques'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
        
        return $reponse;
    }












    public function getDate() {
        // Initialisation de la réponse
        $reponse = array('statut' => 1, 'message' => 'ok', 'statistiques' => array());
        
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
        
        try {
            // Préparation de la requête pour obtenir les statistiques
            $sql = 'SELECT date FROM partie';
            $s = $this->bdd->prepare($sql);
            
            // Exécution de la requête
            $s->execute();
        
            // Vérification de l'exécution de la requête
            if ($s->rowCount() == 0) {
                $reponse['statut'] = 0;
                $reponse['message'] = 'Aucune date disponible';
                return $reponse;
            }
        
            // Extraction des données
            $donnees = $s->fetchAll(PDO::FETCH_ASSOC);
        
            // Attribution des données à la réponse
            $reponse['statistiques'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
        
        return $reponse;
    }
    














    public function getJoueurs() {
        $reponse = array('statut' => 1, 'message' => 'ok');
    
        // Connexion à la base de données
        if (!$this->connexionBDD()) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'connexion bdd impossible';
            return $reponse;
        }
    
        try {
            // Préparation de la requête
            $sql = 'SELECT * FROM joueurs';
            $s = $this->bdd->prepare($sql);
    
            // Exécution de la requête
            $s->execute();
    
            // Extraction des données
            $donnees = $s->fetchAll(PDO::FETCH_ASSOC);
    
            // Attribution des données à la réponse
            $reponse['joueurs'] = $donnees;
        } catch (PDOException $e) {
            $reponse['statut'] = 0;
            $reponse['message'] = 'Erreur PDO : ' . $e->getMessage();
        }
    
        return $reponse;
    }
    
}





    
    


