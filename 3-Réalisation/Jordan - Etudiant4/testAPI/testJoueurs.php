<?php

require_once('dataJoueurs.php');

$plots_lumineux = new plots_lumineux();

$joueur = array('password'=>'1234','email'=>'exemple@mail','identifiant'=>'test');

//test create
$resultat = $plots_lumineux->createJoueur($joueur);
var_dump($resultat);

//test get all
var_dump($plots_lumineux->getJoueurs());

//test get 
$joueur = $plots_lumineux->getJoueur($resultat['data']['id'])['data'];
var_dump($joueur);

//test update
$joueur['numCarte'] = '12345';
$resultat = $plots_lumineux->updateJoueur($joueur);
var_dump($resultat);

//test delete
var_dump($plots_lumineux->deleteJoueur($resultat['data']['id']));
var_dump($plots_lumineux->getJoueurs());




