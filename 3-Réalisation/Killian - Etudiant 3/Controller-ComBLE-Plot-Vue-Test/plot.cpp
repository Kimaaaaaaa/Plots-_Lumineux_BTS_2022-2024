#include "plot.h"

/*Constructeur*/




Plot::Plot()
{
    connect(this, &Plot::tempsRecu,
            this, &Plot::standBy);







    this->couleur = nullptr;
    lireBatterie();
    nvBatterie = 10;

}

/*Méthode*/

void Plot::lireBatterie()
{
    //this->nvBatterie = 70;

    //this->m_com->
}



bool Plot::activerPlot(Plot * plot, QString couleur)
{
    plot->couleur = couleur;

    //Composer le code permettant d'allumer le plot

    return true;

}

bool Plot::desactiverPlot(Plot *)
{
    //Composer le code permettat au plot de s'éteindre (Couleur éteindre ?)

    return true;
}

void Plot::setNvBatterie(int nv)
{
    nvBatterie = nv;
}

int Plot::getNvBatterie()
{
    return nvBatterie;
}

QString Plot::getNom()
{
    return m_nom;
}

QString Plot::nom() const
{
    return m_nom;
}

void Plot::setNom(const QString &nom)
{
    if (m_nom != nom) {
        m_nom = nom;
        emit nomChanged();
    }
}

void Plot::setId(const int id)
{
    this->m_id = id;
}

int Plot::getId() const {
    return m_id;
}



//Slot

void Plot::standBy()
{
/*
    for(int i = 0; i < this->listePlot.count(); i++)
    {
        desactiverPlot(listePlot.takeAt(i));
    }*/

    //Bloquer 1 seconde......
}

QLowEnergyController *Plot::getControllerBle() const
{
    return controllerBle;
}

void Plot::setControllerBle(QLowEnergyController *newController)
{
    controllerBle = newController;
}





