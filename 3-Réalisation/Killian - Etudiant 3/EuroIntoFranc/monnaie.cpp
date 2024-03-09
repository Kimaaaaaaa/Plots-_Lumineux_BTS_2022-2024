#include "monnaie.h"

monnaie::monnaie(QObject *parent, double valeur, double tauxEuro)
    : QObject{parent}
{
    this->valeur = valeur;
    this->tauxEuro = tauxEuro;
}


/*Getters*/

double monnaie::getValeur(){
    return valeur;

}

double monnaie::getTauxEuro(){
    return tauxEuro;
}

/*Setters*/

void monnaie::setValeur(double valeur)
{
    this->valeur = valeur;
}

void monnaie::setTauxEuro(double tauxEuro)
{
    this->tauxEuro = tauxEuro;
}



