#include "plot.h"

/*Constructeur*/

int Plot::s_nextId = 1;

Plot::Plot()
{
    connect(this, &Plot::tempsRecu,
            this, &Plot::standBy);


    m_id = s_nextId++;
    this->couleur = nullptr;
    lireBatterie(this);
    nvBatterie = 10;

    this->listePlot.append(this);
}

/*Méthode*/

void Plot::lireBatterie(Plot *)
{
    this->nvBatterie = 70; //valeur fictive en attendant de recevoir la donnée batterie
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

int Plot::getNvBatterie()
{
    return nvBatterie;
}

QString Plot::getNom()
{
    return m_nom;
}

//Slot

void Plot::standBy()
{

    for(int i = 0; i < this->listePlot.count(); i++)
    {
        desactiverPlot(listePlot.takeAt(i));
    }

    //Bloquer 1 seconde......

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

int Plot::getId() const {
    return m_id;
}




