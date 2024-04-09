#include "partie.h"

Partie::Partie(int nbJoueur, int tempsPourAppuyer, QObject *parent) : QObject(parent)
{
    this->nbJoueur  =nbJoueur;
    this->tempsPourAppuyer = tempsPourAppuyer;




}
