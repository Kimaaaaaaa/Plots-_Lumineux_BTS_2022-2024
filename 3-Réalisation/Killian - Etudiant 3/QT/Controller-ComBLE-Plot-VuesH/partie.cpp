#include "partie.h"

Partie::Partie(int tempsPourAppuyer, int nbCoup, QString couleurJ1, QString couleurJ2, QObject *parent) : QObject(parent)
{
    this->couleurJ1  =couleurJ1;
    this->couleurJ2  =couleurJ2;
    this->tempsPourAppuyer = tempsPourAppuyer;
    this->nbCoup = nbCoup;
    this->tourCourant = 0;
    this->plotTouche = 0;
    this->isColorRandom = false;
    this->isLaunched = false;


}

int Partie::getTourCourant() const
{
    return tourCourant;
}

void Partie::setTourCourant(int newTourCourant)
{
    tourCourant = newTourCourant;
}

bool Partie::getIsLaunched() const
{
    return isLaunched;
}

void Partie::setIsLaunched(bool newIsLaunched)
{
    isLaunched = newIsLaunched;
}

const QString &Partie::getCouleurJ1() const
{
    return couleurJ1;
}

const QString &Partie::getCouleurJ2() const
{
    return couleurJ2;
}

int Partie::getTempsPourAppuyer() const
{
    return tempsPourAppuyer;
}

int Partie::getNbCoup() const
{
    return nbCoup;
}

const QList<Plot *> &Partie::getListePlotPartie() const
{
    return listePlotPartie;
}

int Partie::getPlotTouche() const
{
    return plotTouche;
}

void Partie::setPlotTouche(int newPlotTouche)
{
    plotTouche = newPlotTouche;
}

bool Partie::getIsColorRandom() const
{
    return isColorRandom;
}

void Partie::setIsColorRandom(bool newIsColorRandom)
{
    isColorRandom = newIsColorRandom;
}

void Partie::setCouleurJ1(const QString &newCouleurJ1)
{
    couleurJ1 = newCouleurJ1;
}

void Partie::setCouleurJ2(const QString &newCouleurJ2)
{
    couleurJ2 = newCouleurJ2;
}
