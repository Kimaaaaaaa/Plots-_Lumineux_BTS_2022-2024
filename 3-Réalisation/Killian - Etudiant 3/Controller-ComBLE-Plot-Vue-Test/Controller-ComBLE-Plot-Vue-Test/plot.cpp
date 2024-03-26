/*Plot.cpp*/


#include "plot.h"

/*Constructeur*/


int Plot::s_nextId = 1;

Plot::Plot()
{
    connect(this, &Plot::tempsRecu,
            this, &Plot::standBy);
    m_id = s_nextId++;
    qDebug() << "ID DU PLOT COURANT : "<<m_id;









    this->couleur = nullptr;
    nvBatterie = 10;
    selected = false;

}

/*Méthode*/




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

bool Plot::getSelected()
{
    return selected;
}

void Plot::setSelected(bool selected)
{
    this->selected = selected;
    qDebug()<<"Selected changed : ";
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





