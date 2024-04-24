<?php

require_once('dataJoueurs.php');

$plots_lumineux = new plots_lumineux();

$id = 1;


$joueur = array('password'=>'123','email'=>'nouveau@mail','identifiant'=>'nouveauJ');

//test creer OK
$resultat = $plots_lumineux->createJoueur($joueur);
//var_dump($resultat);

//test get all OK
var_dump($plots_lumineux->getJoueurs());

//test get OK
$id=144;
$joueur = $plots_lumineux->getjoueur($id);
var_dump($joueur);


//test modifier OK
/*$joueurUpdate = array(
    'id' => 101, 
    'password' => 'testmdp',
    'email' => 'update@mail.com',
    'identifiant' => 'updateJoueur'
);*/

//$resultat = $plots_lumineux->updateJoueur($joueurUpdate);
var_dump($resultat);

//test supprimer OK
//$id=150;
//$joueur = $plots_lumineux->deleteJoueur($id);
var_dump($joueur);

?>



