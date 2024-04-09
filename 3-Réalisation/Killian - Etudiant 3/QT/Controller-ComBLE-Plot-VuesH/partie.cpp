#include "partie.h"

Partie::Partie(int tempsPourAppuyer, int nbCoup, QString couleurJ1, QString couleurJ2, QObject *parent) : QObject(parent)
{
    this->couleurJ1  =couleurJ1;
    this->couleurJ2  =couleurJ2;
    this->tempsPourAppuyer = tempsPourAppuyer;
    this->nbCoup = nbCoup;
    this->tourCourant = 0;


}

int Partie::getTourCourant() const
{
    return tourCourant;
}

void Partie::setTourCourant(int newTourCourant)
{
    tourCourant = newTourCourant;
}
